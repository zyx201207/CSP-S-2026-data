#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, x1, x2, x3, x4;
	int a1, a2;
	cin >> c1 >> s1 >> c2 >> s2;
	a1 = s1[2];
	a2 = s2[2];
	if (c1 == c2)
	{
		x1 = "1";
		if (s1[0] + s1[1] == s2[0] + s2[1])
		{
			x2 = "1";
			if ((a1 == 'A') && (a2 == 'B' || a2 == 'C')) x3 = "1";
			else if ((a1 == 'B') && (a2 == 'A' || a2 == 'C')) x3 = "1";
			else if ((a1 == 'C') && (a2 == 'A' || a2 == 'B')) x3 = "1";
			else if (a1 == 'D' && a2 == 'F') x3 = "1";
			else if (a1 == 'F' && a2 == 'D') x3 = "1";
			if (x3 == "1")
			{
				if (a1 == 'A' && a2 == 'B') x4 = "1";
				else if ((a1 == 'B') && (a2 == 'A' || a2 == 'C')) x4 = "1";
				else if (a1 == 'C' && a2 == 'B') x4 = "1";
				else if (a1 == 'D' && a2 == 'F') x4 = "1";
				else if (a1 == 'F' && a2 == 'D') x4 = "1";
				if (x4 == "1")
				{
					cout << x1 << x2 << x3 << x4;
					return 0;
				}
				else
				{
					x4 = "0";
					cout << x1 << x2 << x3 << x4;
					return 0;
				}
			}
			else
			{
				x3 = x4 = "0";
				cout << x1 << x2 << x3 << x4;
				return 0;
			}
		}
		else
		{
			x2 = x3 = x4 = "0";
			cout << x1 << x2 << x3 << x4;
			return 0;
		}
	}
	else
	{
		x1 = x2 = x3 = x4 = "0";
		cout << x1 << x2 << x3 << x4;
		return 0;
	}
	return 0;
} 
