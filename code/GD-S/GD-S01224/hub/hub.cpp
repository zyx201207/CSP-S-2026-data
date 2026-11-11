#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 5;

int n, k, head[N], etot, dis[N];
vector<int> e[N]; bool vis[N];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) e[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	if (n <= 20) {
		int ans = 2e9; // cout << "Start :\n";
		for (int msk = (1 << k) - 1; msk < (1 << n); ++msk) {
			if (__builtin_popcount(msk) != k) continue;
			
			memset(vis, 0, sizeof(bool) * (n + 1));
			
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (cnt > 2) {
					break; 
				}
				if (!vis[i] && (msk >> i - 1) & 1) {
					auto dfs = [&](auto &&self, int u) -> void {
						vis[u] = true;
						for (auto v : e[u]) {
							if (!vis[v] && (msk >> v - 1) & 1) {
								self(self, v);
							}
						}
					}; dfs(dfs, i);
					++cnt;
					// cout << "visitied: " << i << '\n';
				}
			}
			
			if (cnt > 2) continue;
			
			queue<int> q;
			for (int i = 1; i <= n; ++i) {
				dis[i] = 2e9;
				if ((msk >> i - 1) & 1)  {
					q.push(i), dis[i] = 0;
				}
			}
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (auto v : e[u]) {
					if (dis[v] > dis[u] + 1) {
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}
			int res = 0;
			for (int i = 1; i <= n; ++i) res = max(res, dis[i]);
	//		if (res == 1) cout << "Here: ";
	//		for (int i = 1; i <= n; ++i) cout << ((msk >> i - 1) & 1);
	//		cout << " :  "; for (int i = 1; i <= n; ++i) cout << dis[i] << ' '; cout << '\n'; 
			ans = min(ans, res); // cout << msk << ' ' << res << '\n';
		}
		cout << ans << '\n';
	} else 
	if (k == 2) {
		int ans = 2e9; 
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				queue<int> q;
				q.push(i), q.push(j);
				memset(dis, 0x3f, sizeof(int) * (n + 1));
				dis[i] = dis[j] = 0;
				while (!q.empty()) {
					int u = q.front(); q.pop();
					for (auto v : e[u]) {
						if (dis[v] > dis[u] + 1) {
							dis[v] = dis[u] + 1;
							q.push(v);
						}
					}
				}
				int res = 0; // cout << i << ' ' << j << ':' << ' ';
				for (int k = 1; k <= n; ++k) res = max(res, dis[k]);
//				for (int k = 1; k <= n; ++k) {
//					cout << dis[k] << ' ';
//				} cout << '\n';
				ans = min(ans, res);
			}
		}
		cout << ans << '\n';
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, T; cin >> c >> T;
	while (T--) {
		solve();	
	}
}
