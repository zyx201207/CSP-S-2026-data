#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge
{ int to; ll w; };

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 508, M = 5e5 + 8; 
int n, m, d, q;
ll w[M];
ll g[N][N];
vector<edge> es[M];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%*d%d%d%d%d", &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int x = 1; x <= n; x++)
	{
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= k; i++)
		{
			int v;
			ll ww;
			scanf("%d%lld", &v, &ww);
			es[v].push_back({x, ww});
		}
	}
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= n; i++)
		g[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < (int)es[i].size(); j++)
			for (int k = j + 1; k < (int)es[i].size(); k++)
			{
				int u = es[i][j].to, v = es[i][k].to;
				ll w1 = es[i][j].w, w2 = es[i][k].w;
				g[u][v] = min(g[u][v], w1 + w2);
				g[v][u] = g[u][v];
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while(q--)
	{
		int x, y;
		ll ans = INF;
		scanf("%d%d", &x, &y);
		for (auto u : es[x])
			for (auto v : es[y])
				ans = min(ans, u.w + g[u.to][v.to] + v.w);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}