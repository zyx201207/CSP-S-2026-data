#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace Code {
	constexpr int N = 5e2 + 5;
	constexpr int M = 5e5 + 5;
	constexpr int Q = 1e5 + 5;
	constexpr int inf = 0x3f3f3f3f3f3f3f3f;

	struct Node {
		int l;
		int t;

		Node(int _l, int _t)
			: l(_l),t(_t) {}
	};

	int c, n, m, d, q;

	int w[M];
	int k[N];
	vector < Node > line[M];

	int f[N][N];

	void main() {
		cin >> c >> n >> m >> d >> q;
		for (int i = 1; i <= m; ++ i)
			cin >> w[i];
		for (int i = 1; i <= n; ++ i) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; ++ j) {
				int a, t;
				cin >> a >> t;
				line[a].emplace_back(i, t);
			}
		}

		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				f[i][j] = inf;

		for (int i = 1; i <= m; ++ i) {
			int l = line[i].size();
			for (int x = 0; x < l; ++ x) {
				for (int y = x + 1; y < l; ++ y) {
					auto u = line[i][x];
					auto v = line[i][y];
					if (u.l > v.l) swap(u, v);

					f[u.l][v.l] = min(f[u.l][v.l], u.t + v.t);
				}
			}
		}

		for (int i = 1; i <= n; ++ i)
			for (int j = i + 1; j <= n; ++ j)
				f[j][i] = f[i][j];
		for (int i = 1; i <= n; ++ i)
			f[i][i] = 0;
		
		for (int k = 1; k <= n; ++ k)
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= n; ++ j)
					if (f[i][k] != inf && f[k][j] != inf)
						f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

		for (int i = 1; i <= q; ++ i) {
			int x, y;
			cin >> x >> y;

			int mn = inf;
			for (auto p : line[x])
				for (auto q : line[y])
					mn = min(mn, w[x] + p.t + f[p.l][q.l] + q.t + w[y]);
			
			cout << mn << '\n';
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Code::main();

	return 0;
}