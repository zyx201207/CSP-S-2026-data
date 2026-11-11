#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
//#define int long long
using namespace std;
const int N = 510, M = 3e5 + 10, inf = 1e9;
int c, n, m, d, q, w[M], k[N];
int a[N][M], t[N][M];
int g[N][N];
struct node{
	int to, t;
};
vector <node> ha[M];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 0; i < 505; i++) 
		for (int j = 0; j < 505; j++) 
			g[i][j] = inf;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			ha[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (auto x : ha[i]) {
			for (auto y : ha[i]) {
				if (x.to != y.to)
					g[x.to][y.to] = g[y.to][x.to] = min(g[x.to][y.to], x.t + y.t);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for (auto u : ha[x]) {
			for (auto v : ha[y]) {
				ans = min(ans, g[u.to][v.to]);
			}
		}
		cout << ans + w[x] + w[y]<< '\n';
	}
	return 0;
} 
