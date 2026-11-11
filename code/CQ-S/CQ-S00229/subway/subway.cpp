#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, t, dis[505][505], cnt, vis[600005], diss[600005], aa[1000005];

struct node
{
	long long id, w;
};
node a[500005][25];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> t;
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld", &aa[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		long long s;
		scanf("%lld", &s);
		while(s--)
		{
			long long x, w;
			scanf("%lld %lld", &x, &w);
			a[x][++a[x][0].w] = {i, w};
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dis[i][j] = 1e18;
			if(i == j)
			{
				dis[i][j] = 0;
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= a[i][0].w; j++)
		{
			for(int k = 1; k <= a[i][0].w; k++)
			{
				if(j == k)
				{
					continue;
				}
				dis[a[i][j].id][a[i][k].id] = min(dis[a[i][j].id][a[i][k].id], a[i][j].w + a[i][k].w);
			}
		}
	}
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(t--)
	{
		long long x, y, ans = 1e18;
		scanf("%lld %lld", &x, &y);
		for(int i = 1; i <= a[x][0].w; i++)
		{
			for(int j = 1; j <= a[y][0].w; j++)
			{
				ans = min(ans, dis[a[x][i].id][a[y][j].id] + a[x][i].w + a[y][j].w);
			}
		}
		printf("%lld\n", ans + aa[x] + aa[y]);
	}
	return 0;
}
