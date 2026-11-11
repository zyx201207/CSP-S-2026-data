//孙宇宸 GZ-S00248 贵阳市华师一学校 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using lll = __int128_t;

constexpr ll P = (1ll << 61) - 1;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 1 << 30;
	for (int S = 0; S < 1 << n; ++S) {
		vector<int> vec;
		for (int i = 1; i <= n; ++i) if (S >> (i - 1) & 1) {
			vec.push_back(i);
		}
		if (vec.size() != k) {
			continue;
		}
		vector<bool> vis(n + 1);
		int cnt = 0;
		for (int i = 0; i < k; ++i) {
			int x = vec[i];
			if (!vis[x]) {
				++cnt;
				queue<int> que;
				que.push(x);
				vis[x] = true;
				while (!que.empty()) {
					int u = que.front();
					que.pop();
					for (int v : adj[u]) if (!vis[v]) {
						vis[v] = true;
						que.push(v);
					}
				}
			}
		}
		if (cnt > 2) {
			continue;
		}
		vector<int> d(n + 1, 1 << 30);
		for (int i = 1; i <= n; ++i) {
			vis[i] = false;
		}
		queue<int> que;
		for (int i : vec) {
			d[i] = 0;
			vis[i] = true;
			que.push(i);
		}
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			for (int v : adj[u]) if (!vis[v]) {
				vis[v] = true;
				que.push(v);
				d[v] = d[u] + 1;
			}
		}
		int mx = 0;
		for (int i = 1; i <= n; ++i) {
			mx = max(mx, d[i]);
		}
		ans = min(ans, mx);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	} 
	return 0;
}
