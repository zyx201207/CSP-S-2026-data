#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	char w1 = b[2], w2 = d[2];
	if (a == c)
	{
		cout << 1;
		if (b[0] == d[0] && b[1] == d[1])
		{
			cout << 1;
			if ((int)(w2 - w1) <= 2 && (!(w1 == 'C' && w2 == 'D') || (w1 == 'D' && w2 == 'C')))
			{
				cout << 1;
				if ((int)(w2 - w1) == 1 || (w1 == 'D' && w2 == 'F') || (w1 == 'F' && w2 == 'D'))
				{
					cout << 1;
				}
				else cout << 0;
				cout << "\n";
			}
			else
			{
				cout << "00" << "\n";
				return 0;
			}
		}
		else
		{
			cout << "000" << "\n";
			return 0;
		}
	}
	else
	{
		cout << "0000" << "\n";
		return 0;
	}
	return 0;
}
