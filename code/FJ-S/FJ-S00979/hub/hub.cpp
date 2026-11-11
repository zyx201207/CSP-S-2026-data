#include <bits/stdc++.h>
using namespace std;
const int N = 110;
long long fa[N], n, u[N], v[N], t, c, k, ans, vis[N], G[N][N];
long long find(long long u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> t;
	while (t --) {
		cin >> n >> k;
		memset(G, 0x3f, sizeof G);
		for (int i = 1; i <= n; i ++)
			G[i][i] = 0;
		for (int i = 1; i < n; i ++)
			cin >> u[i] >> v[i], G[u[i]][v[i]] = G[v[i]][u[i]] = 1;
		ans = LLONG_MAX;
		for (int k = 1; k <= n; k ++)
			for (int i = 1; i <= n; i ++)
				for (int j = 1; j <= n; j ++)
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
		for (int i = 0; i < (1 << n); i ++) {
			if (__builtin_popcount(i) != k)
				continue;
			long long res = 0;
			for (int j = 1; j <= n; j ++) {
				fa[j] = j;
				vis[j] = (i >> (j - 1) & 1);
			}
			for (int j = 1; j < n; j ++)
				if (vis[u[j]] && vis[v[j]])
					fa[find(u[j])] = find(v[j]);
			for (int j = 1; j <= n; j ++)
				if (vis[j])
					res += find(j) == j;
			if (res > 2) continue;
			res = 0;
			for (int j = 1; j <= n; j ++)
				if (!vis[j]) {
					long long tmp = LLONG_MAX;
					for (int k = 1; k <= n; k ++)
						if (vis[k]) 
							tmp = min(tmp, G[j][k]);
					res = max(res, tmp);
				}
			ans = min(ans, res);
		}
		cout << ans << "\n";
	}
	return 0;
}

