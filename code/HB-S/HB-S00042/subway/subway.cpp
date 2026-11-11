#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int c, n, m, d, q, w[500010];
long long f[N][N];
vector<pair<int, int>> g[N], edges[500010];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++){
			int x, y;
			scanf("%d%d", &x, &y);
			g[i].push_back(make_pair(x, y));
			edges[x].push_back(make_pair(i, y));
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = 1LL << 60;
	for (int i = 1; i <= n; i++){
		f[i][i] = 0;
		for (auto x : g[i])
			for (auto y : edges[x.first])
				f[i][y.first] = min(f[i][y.first], x.second * 1LL + y.second);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (f[i][k] < (1LL << 60) && (f[k][j] < (1LL << 60)))
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--){
		int u, v;
		scanf("%d%d", &u, &v);
		long long ans = 1LL << 60;
		for (auto x : edges[u])
			for (auto y : edges[v])
				ans = min(ans, f[x.first][y.first] + x.second + y.second);
		printf("%lld\n", ans + w[u] + w[v]);
	}
	return 0;
}
// 1 : 2