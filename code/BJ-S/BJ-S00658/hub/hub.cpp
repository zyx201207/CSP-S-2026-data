#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 15;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
		
	int c, T;
	cin >> c >> T;
	while (T -- ) {
		int n, k;
		cin >> n >> k;
		vector<int> g[n+5];
		int dist[n+5][n+5];
		memset(dist, 0x3f, sizeof dist);
		for (int i = 1; i < n; i ++ ) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			dist[u][v] = 1;
			dist[v][u] = 1;
		}
		for (int i = 1; i <= n; i ++ ) dist[i][i] = 0;
		for (int k = 1; k <= n; k ++ ) 
			for (int i = 1; i <= n; i ++ ) 
				for (int j = 1; j <= n; j ++ )
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
		//for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= n; j ++ ) cout << i << ' ' << j << ' ' << dist[i][j] << endl;
		//cout << endl;
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < (1 << n); i ++ ) {
			int x = i;
			int cnt = 0;
			vector<int> v;
			bool col[n + 5] = {0};
			bool ex[n + 5] = {0};
			int idx = 1;
			while (x) {
				if (x & 1) cnt ++ , v.push_back(idx), ex[idx] = 1;
				x >>= 1; idx ++ ;
			}
			if (cnt != k) continue;
			queue<int> q;
			q.push(v[0]); col[v[0]] = 1;
			while (!q.empty()) {
				int t = q.front(); q.pop();
				for (auto e : g[t]) {
					if (!col[e] && ex[e]) {
						col[e] = 1;
						q.push(e);
					}
				}
			}
			for (auto y : v) {
				if (!col[y]) {
					col[y] = 1;
					q.push(y);
					break;
				}
			}
			while (!q.empty()) {
				int t = q.front(); q.pop();
				for (auto e : g[t]) {
					if (!col[e] && ex[e]) {
						col[e] = 1;
						q.push(e);
					}
				}
			}
			bool flag = true;
			for (auto y : v) {
				if (!col[y]) {
					flag = false;
				}
			}
			if (flag) {
				//for (auto z:v) cout << z << ' ';
				int res = 0;
				for (int y = 1; y <= n; y ++ ) {
					int tmp = 0x3f3f3f3f;
					for (auto z : v) {
						tmp = min(tmp, dist[y][z]);
					}
					res = max(tmp, res);
				}
				ans = min(res, ans);
				//cout << res;
				//cout << endl;
			}
		}
		cout << ans << endl;
	}
}
