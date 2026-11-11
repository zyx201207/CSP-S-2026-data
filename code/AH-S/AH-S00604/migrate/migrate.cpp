#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, a[500005], b[500005], d, n; 
bool flag;
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		cin >> a[1] >> a[2];
		flag = 1;
		for (int i = 3; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		b[2] = a[2] - a[1];
		for (int i = 3; i <= n; i++)
		{
			b[i] = a[i] - a[i - 1];
			if (b[i] != b[i - 1]) flag = 0;
		}
		if (!flag) 
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = i + 3; j <= n; j++)
				{
					for (int k = i + 1; k < j; k++)
					{
						if (a[k] - a[i] <= d && a[j] - a[k] <= d && a[k + 1] - a[i] <= d && a[j] - a[k + 1] <= d)
						{
							if (((a[k - 1] - a[i] > d || a[j] - a[k - 1] > d) || k - 1 == i) && ((a[k + 2] - a[i] > d && a[j] - a[k + 2] > d) || k + 2 == j))
							{
								ans++;
							}
						}
					}
				}
			}
			cout << ans << '\n';
			continue;
		}
		if (d < 2 * b[n]) cout << 0 << '\n';
		else 
		{
			b[n] = d / b[n];
			cout << n - 2 * b[n] + 1 << '\n';
		}
	}
	return 0;
}
