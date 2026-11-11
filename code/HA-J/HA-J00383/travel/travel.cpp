#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	int a = 0,b = 0,c = 0,d = 0;
	string x,y,m,n;
	cin >> x >> y >> m >> n;
	if (x == m && x != "01" && x != "16")
	{
		a = 1;
		if (y[0] == n[0] && y[1] == n[1])
		{
			b = 1;
			if ((y[2] == 'A' && n[2] == 'B') || (y[2] == 'A' && n[2] == 'C') || (y[2] == 'B' && n[2] == 'C') || (y[2] == 'B' && n[2] == 'A') || (y[2] == 'C' && n[2] == 'A') || (y[2] == 'C' && n[2] == 'B') || (y[2] == 'D' && n[2] == 'E') || (y[2] == 'E' && n[2] == 'D'))
			{
				c = 1;
				if ((y[2] == 'A' && n[2] == 'B') || (y[2] == 'B' && n[2] == 'C') || (y[2] == 'B' && n[2] == 'A') || (y[2] == 'C' && n[2] == 'B') || (y[2] == 'D' && n[2] == 'E') || (y[2] == 'E' && n[2] == 'D'))
				{
					d = 1;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
