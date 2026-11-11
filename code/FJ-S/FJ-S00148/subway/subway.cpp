#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int C, n, m, d, q;
vector <pair <int, ll>> edge[500010];
ll f[510][510], w[500010], g[510][510];

int main() {
	freopen("subway.in", "r", stdin);
//	freopen("subway7.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &m, &n, &d, &q);
	memset(f, 60, sizeof(f));
	for (int i = 1 ; i <= m ; i++) f[i][i] = 0;
	d = 0;
	for (int i = 1 ; i <= n ; i++)
		scanf("%lld", &w[i]);
	for (int i = 1 ; i <= m ; i++) {
		int k;
		scanf("%d", &k);
		for (int x, t ; k-- ; ) {
			scanf("%d%d", &x, &t);
			edge[x].push_back({i, t});
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		int k = edge[i].size();
		for (int u = 0 ; u < k ; u++)
			for (int v = u + 1 ; v < k ; v++)
				f[edge[i][u].first][edge[i][v].first] = min(f[edge[i][u].first][edge[i][v].first], edge[i][u].second + edge[i][v].second),
				f[edge[i][v].first][edge[i][u].first] = min(f[edge[i][v].first][edge[i][u].first], edge[i][u].second + edge[i][v].second);
	}
//	for (int i = 1 ; i <= m ; i++) {for (int j = 1 ; j <= m ; j++) cout << f[i][j] << " "; puts(""); }
	for (int k = 1 ; k <= m ; k++) {
		memcpy(g, f, sizeof(g));
		for (int i = 1 ; i <= m ; i++)
			for (int j = 1 ; j <= m ; j++)
				f[i][j] = min(f[i][j], g[i][k] + g[k][j]);
	}
	for (int u, v ; q-- ; ) {
		scanf("%d%d", &u, &v);
		ll ans = 1e18;
		for (auto x : edge[u])
			for (auto y : edge[v])
				ans = min(ans, x.second + y.second + f[x.first][y.first]);
		printf("%lld\n", ans + w[u] + w[v]);
	}
//	cout << clock() << endl;
	return 0;
} 
