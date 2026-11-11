#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int INF = 0x3f3f3f3f, _INF = 0xc0c0c0c0;
const ll LLINF = 0x3f3f3f3f3f3f3f3f, _LLINF = 0xc0c0c0c0c0c0c0c0;

/*
我们直接暴力吧，没时间了。 
*/

const int N = 1e5 +10;
int c, t;
int n ,k;
std::vector<int> g[N];
std::vector<int>vec;
bool chosen[N];
bool vis[N];

int ans = INF;
int mn = INF;

void dfs2(int u, int pre) {
	vis[u] = true;
	for (int &v :g[u]) {
		if (!chosen[v]) continue;
		if (v == pre) continue;
		dfs2(v, u);
	}
}

void dfs3(int u, int pre, int step) {
	if (chosen[u]) mn = std::min(mn, step);
	for (int &v :g[u]) {
		if (v == pre) continue;
		dfs3(v, u, step +1);
	}
}

void dfs(int curr, int cnt) {
	if (cnt == k) {
		
//		std::cerr << '\n';
		for (int &i :vec) vis[i] = false;
		int cnt2 = 0;
		for (int &i :vec) {
			if (!vis[i]) {
				cnt2++;
				if (cnt2 > 2) return;
				dfs2(i, 0);
			}
		}

		
		
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			mn = INF;
			dfs3(i, 0, 0);
//			std::cerr << mn << ' ';
			mx = std::max(mx, mn);
		}
//		std::cerr << '\n';
		
		ans = std::min(ans, mx);
		return;
	}
	for (int i = curr + 1; i <= n; i++) {
		vec.push_back(i);
		chosen[i] = true;
		dfs(i, cnt +1);
		chosen[i] = false;
		vec.pop_back();
	}
}

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans = INF;
	
	dfs(0, 0);
	std::cout << ans << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false); std::cin.tie(0);

	std::cin >> c >> t;
	while (t--) solve();

	return 0;
}

