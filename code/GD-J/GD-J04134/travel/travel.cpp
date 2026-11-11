#include <bits/stdc++.h>
using namespace std;

string n, m, x, y;

int w(char x)
{
	if (x <= 'C')
		return 1;
	else
		return 0;
}

int w2(char x)
{
	if (x == 'D')
		return 5;
	return x - 'A' + 1;
}

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> x >> m >> y;
	if (n == m)
	{
		if (x[0] == y[0] && x[1] == y[1])
		{
			if (w(x[2]) == w(y[2]))
			{
				if (abs(w2(x[2]) - w2(y[2])) == 1)
					cout << "1111";
				else
					cout << "1110";
			}
			else
				cout << "1100";
		}
		else
			cout << "1000";
	}
	else
		cout << "0000";
	return 0;
}
