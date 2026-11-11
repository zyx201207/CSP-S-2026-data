#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define pii pair<int, int>

using namespace std;

const int N = 520, M = 5e5 + 10, Inf = 1e18;

int c, n, m, d, q;
int w[M];
vector<pii> v[M];
int f[N][N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++ )
		scanf("%lld", w + i);
	for (int i = 1; i <= n; i ++ ) {
		int k;
		scanf("%lld", &k);
		for (int j = 1; j <= k; j ++ ) {
			int a, t;
			scanf("%lld%lld", &a, &t);
			v[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j < i; j ++ )
			f[i][j] = f[j][i] = Inf;
	for (int i = 1; i <= m; i ++ ) {
		int x = v[i].size();
		for (int j = 0; j < x; j ++ )
			for (int k = 0; k < j; k ++ ) {
				pii u = v[i][j], V = v[i][k];
				int uu = u.first, vv = V.first, w = u.second + V.second;
				f[uu][vv] = min(f[uu][vv], w), f[vv][uu] = min(f[vv][uu], w);
			}
	}
	for (int u = 1; u <= n; u ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				f[i][j] = min(f[i][j], f[i][u] + f[u][j]);
	while (q -- ) {
		int u, V, ans = Inf;
		scanf("%lld%lld", &u, &V);
		for (auto x : v[u])
			for (auto y : v[V])
				ans = min(ans, f[x.first][y.first] + x.second + y.second);
		printf("%lld\n", ans + w[u] + w[V]);
	}
	return 0;
}
