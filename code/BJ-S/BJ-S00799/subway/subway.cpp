#include <bits/stdc++.h>
using namespace std;

const int N = 1005, M = 1e5+5;
const long long inf = 1e18;

int c, n, m, d, q, k[N], u, v;
long long dis[N][N];
long long t[N][M], wei[M], g[N][N];


int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> wei[i];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			g[i][j] = inf;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		cin >> u >> t[i][1] >> v >> t[i][2];
		long long time = t[i][1]+t[i][2];
		g[u][v] = min(g[u][v], time);
		g[v][u] = min(g[v][u], time);
	}
	n = m;
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
		{
			dis[u][v] = g[u][v];
			//cout << dis[u][v] << ' ';
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	for (int i = 1; i <= q; i++)
	{
		cin >> u >> v;
		cout << wei[u]+dis[u][v]+wei[v] << '\n';
	}
	return 0;
}
