#include <bits/stdc++.h>
#define int long long
using namespace std;

const int Inf = 1e18;

int c, t, n, d;
vector<int> x, dis, cnt;
vector<vector<int>> adj;

void bfs(int s) {
	dis.assign(n + 1, Inf);
	cnt.assign(n + 1, 0);
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	cnt[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dis[u] + 1 == dis[v]) {
				cnt[v] += cnt[u];
			} else if (dis[u] + 1 < dis[v]) {
				cnt[v] = cnt[u];
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		x.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> x[i];
		adj.assign(n + 1, {});
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					adj[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			bfs(i);
			for (int j = i + 1; j <= n; j++) {
				if (cnt[j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
