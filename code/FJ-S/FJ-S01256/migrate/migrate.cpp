#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005], ans, dis;
bool tp(int i, int j)
{
	if ((j - i + 1) % d == 0)
	{
		dis = (j - i + 1) / d;
	}
	else
	{
		dis = (j - i + 1) / d + 1;
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		ans = 0;/*
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (tp(i, j))
				{
					ans++;
				}
			}
		}*/
		if (a[2] - a[1] <= d)
		{
			cout << n - 3 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
