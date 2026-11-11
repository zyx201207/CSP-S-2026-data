#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, n, k;
int dfn[N], low[N];
vector <int> e[N];
void tarjan(int u, int fa) {
	for (auto v : e[u]) {
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[v] = min(dfn[u], low[u]);
		}
		else low[v] = min(dfn[v], low[u]);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < N; ++i) {
			e[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		tarjan(1, 0);
	}
	return 0;
}