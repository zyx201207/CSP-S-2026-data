#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f
using namespace std;
namespace hz {
	int c, n, m, D, q;
	int p[1000005], d[1000005], vis[1000005];
	vector<pair<int, int>>g[1000005];
	inline int Dijkstra(int S, int T) {
		for (int i = 0; i <= m; i++) {
			d[i] = INF;
		} d[S] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		pq.push({0, S});
		while (!pq.empty()) {
			auto [t, u] = pq.top();
			pq.pop();
			for (int i = 0; i < g[u].size(); i++) {
				auto [v, w] = g[u][i];
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					pq.push({d[v], v});
				}
			} 
		}
//		for (int i = 1; i <= m; i++) {
//			cout << d[i] << " ";
//		}  cout << endl;
		return d[T];
	}
	int a[505][100005], t[505][100005], op[505];
	map<pair<int, int>, bool>mp;
	signed main() {
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		cin >> c >> n >> m >> D >> q;
		for (int i = 1; i <= m; i++) {
			cin >> p[i];
		}
		for (int i = 1; i <= n; i++) {
			int op;
			cin >> op;
			for (int j = 1; j <= op; j++) {
				cin >> a[i][j] >> t[i][j];
			}
			for (int j = 1; j <= op; j++) {
				for (int k = 1; k <= op; k++) {
					if (j == k) continue;
					g[a[i][j]].push_back({a[i][k], t[i][j] + t[i][k]});
					g[a[i][k]].push_back({a[i][j], t[i][j] + t[i][k]});
				}
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << Dijkstra(x, y) + p[x] + p[y] << endl;
		}
		return 0;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	hz::main();
	return 0;
}

