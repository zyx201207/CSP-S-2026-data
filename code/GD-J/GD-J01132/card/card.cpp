#include <bits/stdc++.h>
using namespace std;

int a[500500], isl[500500], vis[500500], ans[500050];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int cur = 1; cur <= n; ++cur)
	{
		memset(isl, 0, sizeof isl);
		memset(vis, 0, sizeof vis);
		int now = 0;
		for (int i = cur; i <= n; ++i)
		{
			now++;
			if (vis[i])
			{
				continue;
			}
			if (!isl[a[i]])
			{
				isl[a[i]] = now;
			}
			else
			{
				for (int j = isl[a[i]] + 1; j <= now; ++j)
				{
					isl[a[j]] = 0;
					vis[j] = 1;
				}
				now = isl[a[i]];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (!vis[i])
			{
				ans[i]++;
			}
		}
		cur++;
	}
	for (int i = 1; i <= m; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
} 
