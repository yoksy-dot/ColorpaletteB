
#include "stdafx.h"
#include <iostream>
#include <random>
#include <windows.h>

void setColor(int fg, int bg);
void setColor(int bg);


int main()
{
	static int ColorNum = 5;

	std::random_device rnd;
	std::mt19937 mt(rnd());

	int* _array = new int[ColorNum];

	std::cout << "カラーパレット\n\n";
	std::cout << "Enterで色を作成します,他の文字を入力することで終了することができます\n";

	while (getchar() == '\n') {

		std::uniform_int_distribution<> rand100(0, 255);
		std::cout << "Color X:" << " YYY \n";
		for (int i = 0; i < ColorNum; ++i) {

			_array[i] = rand100(mt);
			setColor(_array[i]);

			//std::cout << _array[i] << "\n";
			std::cout << "Color " << i << ":" << _array[i] << "\n";
		}

		setColor(0x07, 0);//一応、初期化
	}
	return 0;
}

//文字と背景色
void setColor(int fg, int bg)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;
	if (fg & 0x08)
		attr |= FOREGROUND_INTENSITY;
	if (fg & 0x04)
		attr |= FOREGROUND_RED;
	if (fg & 0x02)
		attr |= FOREGROUND_GREEN;
	if (fg & 0x01)
		attr |= FOREGROUND_BLUE;

	if (bg & 0x08)
		attr |= BACKGROUND_INTENSITY;
	if (bg & 0x04)
		attr |= BACKGROUND_RED;
	if (bg & 0x02)
		attr |= BACKGROUND_GREEN;
	if (bg & 0x01)
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(hCons, attr);
}

//背景色のみ
void setColor(int bg)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;

	if (bg & 0x08)
		attr |= BACKGROUND_INTENSITY;
	if (bg & 0x04)
		attr |= BACKGROUND_RED;
	if (bg & 0x02)
		attr |= BACKGROUND_GREEN;
	if (bg & 0x01)
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(hCons, attr);
}




