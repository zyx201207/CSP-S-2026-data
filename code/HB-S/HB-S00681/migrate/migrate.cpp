#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, ans, x[2000010], dis[2000010], cnt[2000010];
vector<int> e[2000010];
queue<int> q;
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &d), ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]), e[i].clear();
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (abs(x[i] - x[j]) <= d)
					e[i].push_back(j);
		for (int i = 1; i <= n; i++)
		{
			for (int i = 1; i <= n; i++)
				dis[i] = -1, cnt[i] = 0;
			q.push(i), dis[i] = 0, cnt[i] = 1;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int j = 0; j < e[u].size(); j++)
				{
					int v = e[u][j];
					if (dis[v] == -1)
						dis[v] = dis[u] + 1, cnt[v] = cnt[u], q.push(v);
					else if (dis[v] == dis[u] + 1)
						cnt[v] += cnt[u];
				}
			}
			for (int i = 1; i <= n; i++)
				ans += cnt[i] == 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
