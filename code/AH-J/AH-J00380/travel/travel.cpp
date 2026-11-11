#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int R1, X1;
	char R2[4], X2[4];
	short a = 0, b = 0, c = 0, d = 0;
	cin >> R1 >> R2 >> X1 >> X2;
	if(R1 == X1)
	{
		a = 1;
		if(R2[0] == X2[0] && R2[1] == X2[1])
		{
			b = 1;
		}
		if(R2[2] - X2[2] == 1 || R2[2] - X2[2] == -1 || (R2[2] == 'D' && X2[2] == 'F'))
		{
			d = 1;
		}
		if((R2[2] == 'C' && X2[2] == 'D') || (X2[2] == 'C' && R2[2] == 'D'))
		{
			d = 0;
		}
		if((R2[2] == 'A' && X2[2] == 'B') || (R2[2] == 'B' && X2[2] == 'C') || (R2[2] == 'D' && X2[2] == 'F'))
		{
			c = 1;
		}
		if((X2[2] == 'A' && R2[2] == 'B') || (X2[2] == 'B' && R2[2] == 'C') || (X2[2] == 'D' && R2[2] == 'F'))
		{
			c = 1;
		}
	}
	cout << a << b << c << d;
	return 0;
}

