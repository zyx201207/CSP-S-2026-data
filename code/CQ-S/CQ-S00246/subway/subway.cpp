#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

namespace code {
	const int N = 505, M = 5e5 + 5;
	int c, n, m, d, q;
	ll a[M], dis[N][N];
	bool vis[N + M];
	vector<pair<int, int>> s[M], g[N];
	
	void dij(int idx) {
		for(int i = 1; i <= n; i++) {
			vis[i] = false;
			dis[idx][i] = 1e18;
		}
		dis[idx][idx] = 0;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
		q.emplace(0, idx);
		while(q.size()) {
			int u = q.top().second;
			q.pop();
			for(auto i : g[u]) {
				int v = i.first, w = i.second;
				if(dis[idx][v] > dis[idx][u] + w) {
					dis[idx][v] = dis[idx][u] + w;
					q.emplace(dis[idx][v], v);
				}
			}
		}
	}
	
	void niam() {
		cin >> c >> n >> m >> d >> q;
		for(int i = 1; i <= m; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++) {
			int k, x, y;
			cin >> k;
			for(int j = 1; j <= k; j++) {
				cin >> x >> y;
				s[x].emplace_back(i, y);
			}
		}
		for(int i = 1; i <= m; i++) {
			if(s[i].size() >= 2) {
				for(auto u : s[i])
					for(auto v : s[i]) {
						if(u.first != v.first)
							g[u.first].emplace_back(v.first, u.second + v.second);
					}
			}
		}
		for(int i = 1; i <= n; i++)
			dij(i);
		while(q--) {
			int x, y;
			cin >> x >> y;
			ll ans = 1e18;
			for(auto u : s[x])
				for(auto v : s[y]) {
					ans = min(ans, a[x] + u.second + dis[u.first][v.first] + v.second + a[y]);
				}
			cout << ans << '\n';
		}
	}
}

signed main() {
#ifndef _NO_FREOPEN_
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	code::niam();
	
	return 0;
}
