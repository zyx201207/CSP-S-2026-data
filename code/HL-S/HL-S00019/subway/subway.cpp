#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10, K = 510;
typedef pair<int, int> pii;
int c, n, m, d, q, w[N], f[K][K], t[K][100010], edge[K][100010];
vector<pii> e[N];
void Solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	memset(edge, 0x3f, sizeof(edge));
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		while (k--) {
			int a, t; cin >> a >> t;
			e[i].push_back({a, t});
			edge[i][a] = t;
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; ++i) f[i][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (auto it : e[i]) {
			for (int j = i + 1; j <= n; ++j) {
				f[i][j] = f[j][i] = min(f[i][j], it.second + edge[j][it.first]);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	memset(t, 0x3f, sizeof(t));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (auto it : e[j]) {
				t[i][it.first] = min(t[i][it.first], f[i][j] + it.second);
			}
		}
	}
	while (q--) {
		int x, y; cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= n; ++i) {
			ans = min(ans, edge[i][x] + t[i][y]);
		}
		cout << ans + w[x] + w[y] << "\n";
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) Solve();
	return 0;
}
/*
求出来 k 的 floyd
*/