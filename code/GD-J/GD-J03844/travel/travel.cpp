#include <bits/stdc++.h>
using namespace std;

bool q[5];

bool check(char q, char a)
{
	if ((q == 'B' && a == 'D') || (q == 'D' && a == 'B') || (q == 'C' && a == 'D') || (q == 'D' && a == 'C') || (q == 'C' && a == 'E') || (q == 'E' && a == 'C'))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, w1, w2;
	cin >> c1 >> w1 >> c2 >> w2;
	if (c1 == c2)
	{
		q[1] = 1;
		if (w1[0] == w2[0] && w1[1] == w2[1])
		{
			q[2] = 1;
			if (w1[0] == w2[0] && w1[1] == w2[1])
			{
				if (check(w1[2], w2[2]))
				{
					q[3] = 1;
					if (abs(int(w1[2] - w2[2])) == 1)
					{
						q[4] = 1;
						cout << q[1] << q[2] << q[3] << q[4];
					}
					else
					{
						cout << q[1] << q[2] << q[3] << q[4];
					}
				}
				else
				{
					cout << q[1] << q[2] << q[3] << q[4];
				}
			}
		}
		else
		{
			cout << q[1] << q[2] << q[3] << q[4];
		}
	}
	else
	{
		cout << q[1] << q[2] << q[3] << q[4];
	}
	return 0;
}
