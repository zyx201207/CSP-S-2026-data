#include <bits/stdc++.h>

using namespace std;

#define int long long

const int M = 500010, N = 510;

int c, n, m, d, q;
int w[M];
vector <array <int, 2>> dt[M];

int dis[N][N];
signed main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++)
	{
		int k; scanf("%lld", &k);
		while (k--)
		{
			int a, t; scanf("%lld %lld", &a, &t);
			dt[a].push_back({i, t});
		}
	}
	
	memset(dis, 63, sizeof dis);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
		for (auto u : dt[i])
			for (auto v : dt[i])
				dis[u[0]][v[0]] = min(dis[u[0]][v[0]], u[1] + v[1]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	while (q--)
	{
		int x, y; scanf("%lld %lld", &x, &y);
		int Ans = 1e18;
		for (auto u : dt[x])
			for (auto v : dt[y])
				Ans = min(Ans, w[x] + w[y] + u[1] + v[1] + dis[u[0]][v[0]]);
		printf("%lld\n", Ans);
	}
	return 0;
}
// Only feels like nothing could be better when I with you, when I with you ~ 
// Dancing all night pray we're next together it's a breakthough, it's a breakthough ~
