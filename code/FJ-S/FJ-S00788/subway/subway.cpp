#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 505;
int c, n, m, d, q, w[MAXN], k[MAXN], f[MAXM][MAXM], kk[MAXN];
vector<pair<int, int> > g[MAXN];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		cin >> kk[i];
		for(int j = 1, a, t; j <= kk[i]; j ++) {
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i ++) f[i][i] = 0;
	for(int i = 1; i <= m; i ++) {
		for(int j = 0; j < g[i].size(); j ++) {
			for(int k = 0; k < g[i].size(); k ++) {
				f[g[i][j].first][g[i][k].first] = min(f[g[i][j].first][g[i][k].first], g[i][j].second + g[i][k].second);
			}
		}
	}
	for(int k = 1; k <= n; k ++) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for(int i = 1, u, v; i <= q; i ++) {
		cin >> u >> v;
		int ans = 1e18;
		for(int j = 0; j < g[u].size(); j ++) {
			for(int k = 0; k < g[v].size(); k ++) {
				ans = min(ans, g[u][j].second + g[v][k].second + f[g[u][j].first][g[v][k].first]);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}
