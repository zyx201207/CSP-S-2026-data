#include <bits/stdc++.h>
using namespace std;
const int num[10] = {0, 0, 0, 1, 1, 1, 1};
string c1, s1, c2, s2, x, y;
char a, b;
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	x = s1. substr(0, 2);
	y = s2. substr(0, 2);
	a = s1[2], b = s2[2];
	if (a == 'F') a = 'E';
	if (b == 'F') b = 'E';
	if (c1 == c2) 
	{
		cout << '1';
		if (x == y)
		{
			cout << '1';
			if (num[a - 'A'] == num[b - 'A'])
			{
				cout << '1';
				if (a + 1 == b || a - 1 == b || b + 1 == a || b - 1 == a) cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
