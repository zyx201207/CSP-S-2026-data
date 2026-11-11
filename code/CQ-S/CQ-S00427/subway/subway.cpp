#include <bits/stdc++.h>

#define int long long
#define PII pair<int, int>

using namespace std;

namespace zcq_qwq {
	const int N = 5e5 + 5, M = 500 + 5, inf = 0x3f3f3f3f3f3f3f3f;
	
	int c, n, m, D, q;
	
	int d[M][M], a[N];
	
	vector<PII> line[M], G[N];
	
	void main() {
		cin >> c >> n >> m >> D >> q;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++) {
				int x, y;
				cin >> x >> y;
				G[x].push_back({i, y});
				line[i].push_back({x, y});
			}
		}
		memset(d, 0x3f, sizeof d);
		for (int i = 1; i <= n; i++) d[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			for (auto j : line[i]) {
				int to = j.first, w = j.second;
				for (auto k : G[to]) {
					d[i][k.first] = d[k.first][i] = min(d[i][k.first], w + k.second);
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				} 
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			int ans = inf;
			for (auto i : G[x]) {
				for (auto j : G[y]) {
					ans = min(ans, d[i.first][j.first] + i.second + j.second + a[x] + a[y]);
				}
			}
			cout << ans << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	zcq_qwq::main();
	return 0;
}

/*
注意到，我们坐地铁是不花费时间的
所以相当于我们需要找到两条路线，一条是起点所在的，一条是终点所在的
预处理 f[i][j] 表示从线路 i 到达线路 j 的最小时间即可。
跑一个多源最短路. 
然后枚举出边，取最小值，floyd，n ^ 3 + q * d ^ 2达成。 
*/

