// Created by YoungL
// Date: 10/31/2026
#include <bits/stdc++.h>
//#define ONLINE_JUDGE
#define FILENAME "hub"

using ll = long long;
constexpr int N = 4000 + 5;
int c;
int n, k;
std::vector<int> G[N];
int U[N], V[N];
int chs[N];
int fa[N];
bool vis[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		G[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		U[i] = u;
		V[i] = v;
	}
	
	for (int i = 1; i <= n; ++i) {
		chs[i] = i;
	}
	
	int ans = 1e9;
	do {
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
			vis[i] = 0;
		}
		for (int i = 1; i <= k; ++i) {
			vis[chs[i]] = 1;
		}
		
		for (int i = 1; i < n; ++i) {
			if (vis[U[i]] and vis[V[i]]) {
				fa[find(U[i])] = find(V[i]);
			}
		}
		
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (fa[i] == i and vis[i]) ++cnt;
		}
		if (cnt != 2) continue;
		
		int res = 0;
		
		std::queue<std::pair<int, int>> q;
		for (int i = 1; i <= k; ++i) {
			q.emplace(chs[i], 0);
		}
		while (not q.empty()) {
			auto x = q.front();
			q.pop();
			int u = x.first;
			int d = x.second;
			res = std::max(res, d);
			for (auto v : G[u]) {
				if (not vis[v]) {
					vis[v] = 1;
					q.emplace(v, d + 1);
				}
			}
		}
		
//		if (res == 1) {
//			for (int i = 1; i <= k; ++i) std::cerr << chs[i] << " \n"[i == k];
//			for (int i = 1; i <= n; ++i) std::cerr << mark[i] << " \n"[i == n];
//			exit(0);
//		}
		
		ans = std::min(ans, res);
	} while (std::next_permutation(chs + 1, chs + 1 + n));
	std::cout << ans << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif

	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	
	int t;
	std::cin >> c >> t;
	while (t--) {
		solve();
	}

	return 0;
}

