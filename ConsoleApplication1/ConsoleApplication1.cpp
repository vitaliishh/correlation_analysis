// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

using namespace std;


class CoefKorel
{
public:

	double X__ = 0;
	double Y__ = 0;

	double M_xy = 0;
	double D_x = 0;
	double D_y = 0;
	double R_xy = 0;



	void calc(int N, int arrX[], int arrY[])
	{

		for (int i = 0; i < N; i++)
		{
			X__ = X__ + ((1.0 / N) * arrX[i]);

			Y__ = Y__ + ((1.0 / N) * arrY[i]);
		}

		cout << endl << endl;
		cout << "X__: " << X__ << " " << "Y__: " << Y__;
		cout << endl;

		for (int i = 0; i < N; i++)
		{
			M_xy = M_xy + ((1.0 / N) * (arrX[i] - X__) * (arrY[i] - Y__));
		}

		cout << "M_xy: " << M_xy;
		cout << endl;

		for (int i = 0; i < N; i++)
		{
			D_x = D_x + ((1.0 / N) * (pow(arrX[i], 2) - 2 * arrX[i] * X__ + pow(X__, 2)));
			D_y = D_y + ((1.0 / N) * (pow(arrY[i], 2) - 2 * arrY[i] * Y__ + pow(Y__, 2)));
		}

		cout << "D_x: " << D_x << " D_y: " << D_y;
		cout << endl << endl;

		R_xy = M_xy / sqrt(D_x * D_y);

		cout << "R_xy: " << R_xy << endl << endl;
	}


	void printArr(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;
	}


};










class VisualCorArr
{
private:
	int size = 0;
	int* x;
	int* y;

	string** arrH1;
	string** arrH2;
	string** arrH3;
	string** arrH4;

	string sepSym = ".";
	string pointSym = "o";

	bool numberInOrder = false;

public:
	int maxN = 0;
	string** resDiagramNoStyle;

	vector<vector<string>> resDiagramFinaly;




	VisualCorArr(int x[], int y[], int size, bool numberInOrder = false, string sepSym = ".", string pointSym = "o")
	{
		if (numberInOrder == true)
		{
			this->numberInOrder = true;
		}

		this->sepSym = sepSym;
		this->pointSym = pointSym;

		this->size = size;
		this->x = new int[size];
		this->y = new int[size];

		for (int i = 0; i < this->size; i++)
		{
			this->x[i] = x[i];
		}

		for (int i = 0; i < this->size; i++)
		{
			this->y[i] = y[i];
		}


		int sMax = -9999;

		for (int i = 0; i < this->size; i++)
		{
			if (abs(this->x[i]) > sMax)
			{
				sMax = abs(this->x[i]);
			}
		}

		for (int i = 0; i < size; i++)
		{
			if (abs(this->y[i]) > sMax)
			{
				sMax = abs(this->y[i]);
			}
		}

		maxN = sMax + 1;

		arrH1 = new string * [maxN];
		arrH2 = new string * [maxN];
		arrH3 = new string * [maxN];
		arrH4 = new string * [maxN];
		resDiagramNoStyle = new string * [maxN * 2];


		for (int i = 0; i < maxN; i++)
		{
			arrH1[i] = new string[maxN];
		}

		for (int i = 0; i < maxN; i++)
		{
			arrH2[i] = new string[maxN];
		}

		for (int i = 0; i < maxN; i++)
		{
			arrH3[i] = new string[maxN];
		}

		for (int i = 0; i < maxN; i++)
		{
			arrH4[i] = new string[maxN];
		}

		for (int i = 0; i < maxN * 2; i++)
		{
			resDiagramNoStyle[i] = new string[maxN * 2];
		}


		this->fillArrSym(arrH1);
		this->fillArrSym(arrH2);
		this->fillArrSym(arrH3);
		this->fillArrSym(arrH4);


		this->visualArr();

	}

	~VisualCorArr()
	{
		delete[] x;
		delete[] y;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH1[i];
		}

		delete[] arrH1;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH2[i];
		}

		delete[] arrH2;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH3[i];
		}

		delete[] arrH3;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH4[i];
		}

		delete[] arrH4;

		for (int i = 0; i < maxN; i++)
		{
			delete[] resDiagramNoStyle[i];
		}

		delete[] resDiagramNoStyle;


	}


private:

	void fillArrSym(string** arr)
	{
		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				arr[i][k] = this->sepSym;
			}
		}
	}


	void printArr(string** arr)
	{
		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				cout << arr[i][k] << " ";
			}

			cout << endl;
		}
	}


	void drawCorLine()
	{
		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				if (k == 0)
				{
					if (arrH1[i][k] == this->sepSym)
					{
						arrH1[i][k] = "|";
					}
				}

				if (i == maxN - 1)
				{
					if (arrH1[i][k] == this->sepSym)
					{
						arrH1[i][k] = "-";
					}
				}
			}
		}

		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				if (i == maxN - 1)
				{
					if (arrH2[i][k] == this->sepSym)
					{
						arrH2[i][k] = "-";
					}
				}
			}
		}

		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				if (k == 0)
				{
					if (arrH4[i][k] == this->sepSym)
					{
						arrH4[i][k] = "|";
					}
				}
			}
		}
	}

public:

	void visualArr()
	{

		int countCoor = 1;

		for (int i = 0; i < size; i++)
		{
			int x1 = x[i];
			int y1 = y[i];

			if (x1 >= 0 && y1 >= 0)
			{
				if (numberInOrder)
				{
					arrH1[maxN - 1 - y1][x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH1[maxN - 1 - y1][x1] = this->pointSym;
				}
			}
			else if (x1 < 0 && y1 >= 0)
			{
				if (numberInOrder)
				{
					arrH2[maxN - y1 - 1][maxN + x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH2[maxN - y1 - 1][maxN + x1] = this->pointSym;
				}
			}
			else if (x1 < 0 && y1 < 0)
			{
				if (numberInOrder)
				{
					arrH3[y1 * (-1) - 1][maxN + x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH3[y1 * (-1) - 1][maxN + x1] = this->pointSym;
				}
			}
			else if (x1 >= 0 && y1 < 0)
			{
				if (numberInOrder)
				{
					arrH4[y1 * (-1) - 1][x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH4[y1 * (-1) - 1][x1] = this->pointSym;
				}

			}

		}

		this->drawCorLine();


		for (int i = 0; i < maxN * 2; i++)
		{
			for (int k = 0; k < maxN * 2; k++)
			{
				if (i <= maxN - 1 && k <= maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH2[i][k];
				}
				else if (i <= maxN - 1 && k > maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH1[i][k - maxN];
				}
				else if (i > maxN - 1 && k <= maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH3[i - maxN][k];
				}
				else if (i > maxN - 1 && k >= maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH4[i - maxN][k - maxN];
				}
				else {
					resDiagramNoStyle[i][k] = "*";
				}
			}
		}



		vector<string> temp1;

		for (int i = 0; i < maxN * 2 * 2 + 1; i++)
		{
			temp1.push_back("-");

		}

		resDiagramFinaly.push_back(temp1);

		for (int i = 0; i < maxN * 2 - 1; i++)
		{
			vector<string> temp2;

			for (int k = 0; k < maxN * 2; k++)
			{
				if (k == 0)
				{
					temp2.push_back("|");
				}
				else if (i == maxN * 2 - 1)
				{
					temp2.push_back("-");
				}
				else
				{
					temp2.push_back(resDiagramNoStyle[i][k]);
				}

				temp2.push_back(" ");

			}

			temp2.push_back("|");

			resDiagramFinaly.push_back(temp2);

		}

		vector<string> temp3;
		for (int i = 0; i < maxN * 2 * 2 + 1; i++)
		{
			temp3.push_back("-");
		}
		resDiagramFinaly.push_back(temp3);


		for (int i = 0; i < resDiagramFinaly[0].size(); i++)
		{
			if (resDiagramFinaly[resDiagramFinaly.size() / 2][i] == " ")
			{
				resDiagramFinaly[resDiagramFinaly.size() / 2][i] = "-";
			}
		}




	}

	string result()
	{
		string st = "";

		for (int i = 0; i < resDiagramFinaly.size(); i++)
		{
			for (int k = 0; k < resDiagramFinaly[i].size(); k++)
			{
				st = st + resDiagramFinaly[i][k];
			}

			st = st + "\n";
		}


		return st;
	}

};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));



	CoefKorel coefKorel;

	cout << "Введіть N:" << endl;

	int N = 0;

	cin >> N;

	int* x_prob = new int[N];
	int* y_prob = new int[N];

	for (int i = 0; i < N; i++)
	{
		x_prob[i] = rand() % 11 - 5;
		y_prob[i] = rand() % 11 - 5;
	}

	cout << endl << "x_prob:" << endl;
	coefKorel.printArr(x_prob, N);
	cout << endl << "y_prob:" << endl;
	coefKorel.printArr(y_prob, N);



	cout << endl << endl;


	VisualCorArr visualCorArr1(x_prob, y_prob, N);
	string st1 = visualCorArr1.result();
	cout << st1;
	coefKorel.calc(N, x_prob, y_prob);









	int* x_det_up = new int[N];
	int* y_det_up = new int[N];

	int POREGRESSION_NUM1 = 0;
	cout << endl << endl << "Введіть різницю арифметичної прогресії x_det_up:" << endl;
	cin >> POREGRESSION_NUM1;

	int POREGRESSION_NUM2 = 0;
	cout << "Введіть різницю арифметичної прогресії y_det_up:" << endl;
	cin >> POREGRESSION_NUM2;

	int a1 = 0;
	int a2 = 0;
	for (int i = 0; i < N; i++)
	{
		x_det_up[i] = a1 + POREGRESSION_NUM1;
		y_det_up[i] = a1 + POREGRESSION_NUM2;

		a1 = a1 + POREGRESSION_NUM1;
		a2 = a2 + POREGRESSION_NUM2;
	}

	cout << endl << "x_det_up:" << endl;
	coefKorel.printArr(x_det_up, N);
	cout << endl << "y_det_up:" << endl;
	coefKorel.printArr(y_det_up, N);


	VisualCorArr visualCorArr2(x_det_up, y_det_up, N);
	string st2 = visualCorArr2.result();
	cout << st2;
	coefKorel.calc(N, x_det_up, y_det_up);


	int* x_det_down = new int[N];
	int* y_det_down = new int[N];

	int POREGRESSION_NUM3 = 0;
	cout << endl << "Введіть різницю арифметичної прогресії x_det_down:" << endl;
	cin >> POREGRESSION_NUM3;

	int POREGRESSION_NUM4 = 0;
	cout << "Введіть різницю арифметичної прогресії y_det_down:" << endl;
	cin >> POREGRESSION_NUM4;


	int a3 = N;
	int a4 = N;
	for (int i = 0; i < N; i++)
	{
		x_det_down[i] = a3 - POREGRESSION_NUM3;
		y_det_down[i] = a4 - POREGRESSION_NUM4;

		a3 = a3 - POREGRESSION_NUM3;
		a4 = a4 - POREGRESSION_NUM4;
	}

	cout << endl << "x_det_down:" << endl;
	coefKorel.printArr(x_det_down, N);
	cout << endl << "y_det_down:" << endl;
	coefKorel.printArr(y_det_down, N);


	VisualCorArr visualCorArr3(x_det_down, y_det_down, N);
	string st3 = visualCorArr3.result();
	cout << st3;
	coefKorel.calc(N, x_det_down, y_det_down);



	int* x_stoch1 = new int[N];
	int* y_stoch1 = new int[N];
	int* x_stoch2 = new int[N];
	int* y_stoch2 = new int[N];

	for (int i = 0; i < N; i++)
	{
		x_stoch1[i] = x_prob[i] + x_det_up[i];
		y_stoch1[i] = y_prob[i] + y_det_up[i];

		x_stoch2[i] = x_prob[i] + x_det_down[i];
		y_stoch2[i] = y_prob[i] + y_det_down[i];
	}

	cout << endl << endl;
	cout << endl << "x_stoch1 (X prob + X det.up):" << endl;
	coefKorel.printArr(x_stoch1, N);
	cout << endl << "y_stoch1 (Y prob + Y det.up):" << endl;
	coefKorel.printArr(y_stoch1, N);
	cout << endl;
	cout << endl << "x_stoch2 (X prob + X det.down):" << endl;
	coefKorel.printArr(x_stoch2, N);
	cout << endl << "y_stoch2 (Y prob + Y det.down):" << endl;
	coefKorel.printArr(y_stoch2, N);




	/*coefKorel.calc(N, x_prob, y_prob);
	coefKorel.calc(N, x_det_up, y_det_up);
	coefKorel.calc(N, x_det_down, y_det_down);


	coefKorel.calc(N, x_stoch1, y_stoch1);
	coefKorel.calc(N, x_stoch2, y_stoch1);*/




	delete[] x_prob;
	delete[] y_prob;
	delete[] x_det_up;
	delete[] y_det_up;
	delete[] x_det_down;
	delete[] y_det_down;
	delete[] x_stoch1;
	delete[] y_stoch1;
	delete[] x_stoch2;
	delete[] y_stoch2;





}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
