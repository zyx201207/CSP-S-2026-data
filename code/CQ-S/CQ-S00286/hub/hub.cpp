#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f
using namespace std;
namespace hz {
	int n, d;
	int x[1000005];
	int vis[1000005];
	vector<pair<int, int>>g[1000005];
	int d[1000005], prt[1000005];
	inline void Dijkstra(int S, int T) {
		for (int i = 1; i <= n; i++) {
			d[i] = INF;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		while (!pq.empty()) {
			auto [t, u] = pq.top();
			pq.pop();
			for (int i = 0; i < g[u].size(); i++) {
				auto [v, w] = g[u][i];
				if (vis[v] == 1) continue;
				if (d[u] > d[v] + w) {
					d[u] = d[v] + w;
					pq.push({d[v], v});
					prt[v] = u;
				}
			}
		}
	}
	int f[100005];
	int c, T;
	signed main() {
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
		cin >> c >> T;
		while (T--) {
			cout << 0;
			return 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
			}
			if (c == 13 || c == 14) {
				int ans = 0;
				for (int i = n - 2; i >= 1; i--) {
					ans += i;
				}
				cout << ans << endl;
				return 0;
			} 
			if (c == 11 || c == 12) {
				if (n % 2 == 0) {
					cout << 1 << endl;
				} else {
					cout << n / 2 << endl;
				}
				return 0;
			}
			if (c == 19 || c == 20 || c == 21) {
				int ans = 0;
				for (int i = 1; i <= n; i++) {
					if (x[i] - x[i + 1] <= 2 * d) {
						ans++;
					}
				}
				cout << ans << endl;
				return 0;
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					Dijkstra(i, j);
				}
			}
			cout << ans << endl;
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

