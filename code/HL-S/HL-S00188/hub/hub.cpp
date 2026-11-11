#include <bits/stdc++.h>
using namespace std;

namespace OI {

#define int long long
#define endl "\n"

int c, T;

namespace force {
	
constexpr int maxn = 15;

vector<int> graph[maxn];
int depth[maxn], parent[maxn];

int n, k;

void dfs(int u, int fa) {
	depth[u] = depth[fa] + 1;
	parent[u] = fa;
	for (int v : graph[u]) {
		if (v == fa)
			continue;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	while (depth[u] > depth[v])
		u = parent[u];
	if (u == v)
		return u;
	while (parent[u] != parent[v])
		u = parent[u],
		v = parent[v];
	return parent[u];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int dsu[maxn];
inline int find(int x) {
	while (x != dsu[x])
		x = dsu[x] = dsu[dsu[x]];
	return x;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		graph[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	int ans = LONG_LONG_MAX;
	for (int mask = 0; mask < (1 << n); mask++) {
		vector<int> set;
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				set.push_back(i + 1);
		if (set.size() != k)
			continue;
		for (int i = 1; i <= n; i++)
			dsu[i] = i;
		std::set<int> blocks;
		for (int u : set) {
			for (int v : graph[u])
				if (binary_search(set.begin(), set.end(), v) && find(u) != find(v))
					dsu[find(v)] = find(u);
		}
		for (int x : set)
			blocks.insert(find(x));
		if (blocks.size() > 2)
			continue;
		int cur = 0;
		for (int u = 1; u <= n; u++) {
			int now = LONG_LONG_MAX;
			for (int v : set)
				now = min(now, dist(u, v));
			cur = max(cur, now);
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}

}

void main() {
	cin >> c >> T;
	while (T--) {
		switch (c) {
			default:
				force::solve();
				break;
		}
	}
}

#undef int
#undef endl

}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	
	OI::main();
	
	return 0;
}
