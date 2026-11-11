#include <bits/stdc++.h>
using namespace std;

int a, b, d, e;
char c, f;
int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w",stdout);
	cin >> a >> b >> c >> d >> e >> f;
	if (a == d)
	{
		cout << "1";
		if (b  == e)
		{
			cout << "1";
			if (int(c) > int(f))
			{
				char temp = c;
				c = f;
				f = temp;
			}
			if (c == 'A' && f == 'B' || c == 'A' && f == 'C' || c == 'B' && f == 'C' || c == 'D' && f == 'F')
			{
				cout << "1";
				if (c == 'A' && f == 'B' || c == 'B' && f == 'C' || c == 'D' && f == 'F')
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}

