#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 5e5 + 10, M = 510;
int c, n, m, d, q;
int w[N], k[N], edges[M][M];
vector<pair<int, int>> s[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int a, t;
			cin >> a >> t;
			s[a].push_back({i, t});
		}
	}
	memset(edges, 0x3f, sizeof edges);
	for (int i = 1; i <= n; i++) edges[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto p : s[i]) {
			for (auto q : s[i]) {
				int pp = p.first, qq = q.first;
				if (pp == qq) continue;
				edges[pp][qq] = edges[qq][pp] = min(edges[pp][qq], p.second + q.second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
			}
		}	
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for (auto p : s[x]) {
			for (auto q : s[y]) {
				int pp = p.first, qq = q.first;
				ans = min(ans, edges[pp][qq] + p.second + q.second);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
