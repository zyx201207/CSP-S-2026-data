#include <bits/stdc++.h>
using namespace std;
long long c, t;
vector <int> e[20];
bool vis[20], ok[20];
int count(int x)
{
	int cnt = 0;
	while (x)
	{
		if (x% 2 == 1) cnt++;
		x /= 2;
	}
	return cnt;
}
int gi;
void dfs(int x)
{
	vis[x] = 1;
	for (auto y : e[x])
		if (vis[y] == 0 && ok[y] == 1)
			dfs(y);
}
int dis[20];
void work(int x, int di)
{
	dis[x] = min(dis[x], di);
	vis[x] = 1; 
	for (auto y : e[x])
		if (vis[y] == 0)
			work(y, di + 1);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	while (t--)
	{
		long long n, k;
		scanf("%lld %lld", &n, &k);
		for (int i = 1; i <= n; i++)
			e[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans = 1e9;
		for (int i = 0; i < (1 << n); i++)
			if (count(i) == k)
			{
				for (int j = 1; j <= n; j++)
					if ((i & (1 << (j-1))) != 0) ok[j] = 1;
					else ok[j] = 0;
				for (int j = 1; j <= n; j++)
						vis[j] = 0;
				int cnt = 0;
				for (int j = 1; j <= n; j++)
					if (vis[j] == 0 && ok[j] == 1)
					{
						dfs(j);
						cnt++;
					}
				if (cnt <= 2)
				{
					for (int j = 1; j <= n; j++)
						dis[j] = 1e9;
					for (int j = 1; j <= n; j++)
						if (ok[j] == 1)
						{
							for (int k = 1; k <= n; k++)
								vis[k] = 0;
							work(j, 0);
						}
					int mx = 0;
					for (int j = 1; j <= n; j++)
						mx = max(mx, dis[j]);
					ans = min(ans, mx);
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}
