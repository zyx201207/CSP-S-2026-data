#include <bits/stdc++.h>
using namespace std;
int dA_1, dA_2;
string c_1, s_1, c_2, s_2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if (c_1 == c_2)
	{
		printf("1");
	}
	else
	{
		printf("0000\n");
		return 0;
	}
	
	if ((s_1[0] == s_2[0]) && (s_1[1] == s_2[1]))
	{
		printf("1");
	}
	else
	{
		printf("000\n");
		return 0;
	}
	
	dA_1 = s_1[2] - 'A';
	dA_2 = s_2[2] - 'A';
	if ((dA_1 <= 2) && (dA_2 <= 2))
	{
		printf("1");
		if ((dA_1 - dA_2 == 1) || (dA_2 - dA_1 == 1))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	else if ((dA_1 >= 3) && (dA_2 >= 3))
	{
		printf("11\n");
	}
	else
	{
		printf("00\n");
	}
	return 0;
}
