#include <bits/stdc++.h>
using namespace std;

bool chk(string s1, string s2)
{
	if (s1[2] <= 'C')
	{
		return s2[2] <= 'C';
	}
	else
	{
		return s2[2] > 'C';
	}
}
bool chk2(string s1, string s2)
{
	if (s1[2] >= 'D')
	{
		return true;
	}
	else
	{
		if (s1[2] == 'B')
		{
			return true;
		}
		else
		{
			return s2[2] == 'B';
		}
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		string x = s1.substr(0, 2);
		string y = s2.substr(0, 2);
		if (x == y)
		{
			cout << 1;
			if (chk(s1, s2))
			{
				cout << 1;
				if (chk2(s1, s2))
				{
					cout << 1 << endl;
				}
				else
				{
					cout << 0 << endl;
				}
			}
			else
			{
				cout << "00" << endl;
			}
		}
		else
		{
			cout << "000" << endl;
		}
	}
	else
	{
		cout << "0000" << endl;
	}
	return 0;
}
