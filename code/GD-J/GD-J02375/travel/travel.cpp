#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
char c1[5], s1[5], c2[5], s2[5];
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int R1 = 0, R2 = 0, X1 = 0, X2 = 0;
	int Rx = 0, Xx = 0;
	int len = strlen(c1);
	for (int i = 0; i < len; i++)
	{
		R1 = R1 * 10 + (c1[i] - '0');
	}
	len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		if (0 <= s1[i] - '0' && s1[i] - '0' <= 9)
			R2 = R2 * 10 + (s1[i] - '0');
		else
			Rx = s1[i] - 'A' + 1;	
	}
	len = strlen(c2);
	for (int i = 0; i < len; i++)
	{
		X1 = X1 * 10 + (c2[i] - '0');
	}
	len = strlen(s2);
	for (int i = 0; i < len; i++)
	{
		if (0 <= s2[i] - '0' && s2[i] - '0' <= 9)
			X2 = X2 * 10 + (s2[i] - '0');
		else
			Xx = s2[i] - 'A' + 1;
	}			
	if (R1 != X1)
	{
		cout << "0000";
		return 0;
	}
	else
		cout <<1;
	if (R2 == X2)
		 cout << 1;
	else
	{
		cout <<"000"; 
		return 0;
	}
	if ((Rx <= 3 && Xx <= 3) || (Rx > 3 && Xx > 3))
	{
		cout << 1;
	}
	else
	{
		cout <<"00";
		return 0;
	}
	if (abs(Rx - Xx) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}
