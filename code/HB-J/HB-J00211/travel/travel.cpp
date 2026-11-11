#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a = 1,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << '1';
	}
	else
	{
		cout << '0';
	}
	for (int i = 0;i <= 1;i++)
	{
		if (s1[i] != s2[i])
		{
			a = 0;
		}
	}
	cout << a << endl;
	if (a == 1)
	{
		if (s1[2] == 'C' or s1[2] == 'D')
		{
				if (s2[2] == 'C' or s2[2] == 'D')
				{
					cout << '1';
				}
				else
				{
					cout << '0';
				}
		}
		else
		{
			if (s1[2] == 'A' or s1[2] == 'B' or s1[2] == 'C')
			{
				if (s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C')
				{
					cout << '1';
				}
				else
				{
					cout << '0';
				}
			}
		}
	}
	else
	{
		cout << '0';
	}
	if (s1[2] == 'A')
	{
		if (s2[2] == 'B')
		{
			b = 1;
		}
	}
	if (s1[2] == 'B')
	{
		if (s2[2] == 'A' or s2[2] == 'C')
		{
			b = 1;
		}
	}
	if (s1[2] == 'C')
	{
		if (s2[2] == 'B')
		{
			b = 1;
		}
	}
	if (s1[2] == 'C')
	{
		if (s2[2] == 'D')
		{
			b = 1;
		}
	}
	if (s1[2] == 'D')
	{
		if (s2[2] == 'C')
		{
			b = 1;
		}
	}
	cout << b;
	return 0;
}
