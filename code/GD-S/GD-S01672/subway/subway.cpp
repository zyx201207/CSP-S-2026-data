#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std; 
const int maxn = 5e5 + 5, maxm = 505, inf = 1e18;
int c, m, n, d, q, w[maxn], dis[maxm][maxm];
vector <pair <int, int>> vec[maxn];
void cmin(int &a, int b) { if (b < a) a = b; }
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1, k; i <= m; i++) {
		cin >> k;
		for (int j = 1, a, t; j <= k; j++) {
			cin >> a >> t;
			vec[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			dis[i][j] = (i == j ? 0 : inf);
	for (int i = 1; i <= n; i++) 
		for (pair <int, int> u : vec[i]) 
			for (pair <int, int> v : vec[i]) 
				if (u != v) cmin(dis[u.fi][v.fi], u.se + v.se);
	for (int k = 1; k <= m; k++)
		for(int u = 1; u <= m; u++)
			for (int v = 1; v <= m; v++)
				cmin(dis[u][v], dis[u][k] + dis[k][v]);
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		int ans = inf;
		for (pair <int, int> a : vec[u])
			for (pair <int, int> b : vec[v])
				cmin(ans, dis[a.fi][b.fi] + a.se + b.se);
		ans += w[u] + w[v];
		cout << ans << '\n';
	}
	return 0;
}
/*
显然就是一个优化建图和多源最短路 
有 5e5 个地铁站，但是只有 500 个线路，每个站点最多 20 个线路经过
于是想到，只要枚举 u v 连接的地铁线路，然后统计答案
地铁线路只有 500 个且 一次枚举 20^2 次，连边 500000*400 次，但是用 floyd 即可 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
人活着就是为了黑部奈叶香
*/
