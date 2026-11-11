#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2, x, y;
char sum, num;
bool a, b, c, d;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	x += s1[0];
	x += s1[1];
	y += s2[0];
	y += s2[1];
	sum = (char)(s1[2]);
	num = (char)(s2[2]);
	if (c1 == c2)
	{
		a = 1;
		if (x == y)
		{
			b = 1;
			if (sum != 'D' && num != 'D')
			{
				if (sum + 1 == num || sum - 1 == num)
				{
					c = 1;
					d = 1;
				}
				else if (sum != 'F' && num != 'F')
				{
					c = 1;
				}
			}
			else
			{
				if (sum == 'F' || num == 'F')
				{
					c = 1;
					d = 1;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
