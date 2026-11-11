#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string c[2], s[2];
bool cmp(const char &a, const char &b)
{
	return ((((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C') || ((a == 'D' || a == 'F') && (b == 'D' || b == 'F')))));
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c[0] >> s[0] >> c[1] >> s[1];
	if (c[0] == c[1])
	{
		bool pd = true;
		for (int i = 0; i < 2; i++)
			if (s[0][i] != s[1][i])
				pd = false;
		if (pd)
		{
			if (cmp(s[0][2], s[1][2]))
			{
				if (abs(s[0][2] - s[1][2]) == 1)
				{
					cout << "1111";
				}
				else
				{
					cout << "1110";
				}
			}
			else
			{
				cout << "1100";
			}
		}
		else
		{
			cout << "1000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
