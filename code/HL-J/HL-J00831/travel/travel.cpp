#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r");
	freopen("travel.out", "w");
	string s1, s2;
	int a, b;
	cin >> a >> s1 >> b >> s2;
	if (a == b)
	{
		if (a == '02')
		{
			cout << 1;
		}
	}
	else
	{
		cout << 0000;
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < 2; i++)
	{
		if (s1[i] != s2[i])
		{
			ans = 0;
		}
	}
	if (ans == 1)
	{
		cout << 1;
	}
	else
	{
		cout << 000;
		return 0;
	}
	if (s1[2] < 'C')
	{
		if (s2[2] < 'C')
		{
			cout << 1;
			if((s1[2] == 'A') && (s2[2] == 'B'))
			{
				cout << 1;
			}
			else if ((s2[2] == 'A') && (s1[2] == 'B'))
			{
				cout << 1;
			}
			else if ((s2[2] == 'C') && (s1[2] == 'B'))
			{
				cout << 1;
			}
			else if ((s1[2] == 'B') && (s2[2] == 'C'))
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		else
		{
			cout << 00;
		}
	}
	else
	{
		if (s2[2] > 'C')
		{
			cout << 11; 
		}
		else
		{
			cout << 00;
		}
	}
	return 0;
}