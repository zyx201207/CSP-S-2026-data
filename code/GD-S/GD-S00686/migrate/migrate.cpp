#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, d, x[5005];
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
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				int cnt = 0;
				for (int k = i; k <= n; k = upper_bound(x+1, x+n+1, k+d)-x-1)
				{
					cnt++;
				}
			}
		}
	}
	return 0;
}
