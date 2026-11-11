#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 501, M = 5e5+10;
ull inf;
int c, n, m, d, q;
int w[M];
struct Node {
	int id, tm;
};
vector<Node> g[M];
ull ds[N][N];

inline ull get (int x, int y) {
	if (x == y) return 0;
	ull ans = inf;
	for (Node a: g[x]) {
		for (Node b: g[y]) {
			ans = min(ans, w[x] + w[y] + ds[a.id][b.id] + a.tm + b.tm);
		}
	}
	return ans;
}

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int a, k, t;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	memset(ds, 0x3f, sizeof(ds));
	inf = ds[0][0];
	for (int i = 1; i <= n; i++) {
		ds[i][i] = 0ull;
	}
	for (int i = 1; i <= m; i++) {
		Node x, y;
		for (int j = 0; j < g[i].size(); j++) {
			for (int k = j+1; k < g[i].size(); k++) {
				x = g[i][j], y = g[i][k];
				ds[x.id][y.id] = ds[y.id][x.id]
				= min(ds[x.id][y.id], 0ull + x.tm + y.tm);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (ds[i][k] == inf || ds[k][j] == inf) continue;
				ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
			}
		}
	}
	int x, y;
	while (q--) {
		cin >> x >> y;
		cout << get(x, y) << '\n';
	}
	return 0;
} 
