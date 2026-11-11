#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 510, M = 500010;
int n, m, D, Q;
int W[M];
struct Node {
	int x, w;
};
vector<Node> nx[M];
LL g[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _; cin >> _ >> n >> m >> D >> Q;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (i != j) g[i][j] = 1e18;
	for (int i = 1; i <= m; i++) cin >> W[i];
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		int a, t;
		while (k--) {
			cin >> a >> t;
			for (auto [x, w] : nx[a])
				g[i][x] = g[x][i] = min(g[i][x], 1ll * t + w);
			nx[a].push_back({i, t});
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while (Q--) {
		int s, t; cin >> s >> t;
		LL ans = 1e18;
		for (auto [x, w1] : nx[s])
			for (auto [y, w2] : nx[t])
				ans = min(ans, g[x][y] + w1 + w2);
		cout << ans + W[s] + W[t] << "\n";
	}
	return 0;
} 
