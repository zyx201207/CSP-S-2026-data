#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<bool> vis;
vector<int> w;
vector<vector<int>> a, t;
vector<vector<pair<int, int>>> G;
LL ans;

void dfs(int u, int tar, int line, bool chg, LL dis) {
	if(u == tar) {
		ans = min(ans, dis);
		return;
	}
	for(int i = 1; i < a[line].size(); ++i)
		if(!vis[a[line][i]]) {
			vis[a[line][i]] = true;
			dfs(a[line][i], tar, line, false, dis);
			vis[a[line][i]] = false;
		}
	if(!chg)
		for(const auto& nw: G[u])
			if(nw.first != line)
				for(int i = 1; i < t[line].size(); ++i)
					if(a[line][i] == u) {
						dfs(u, tar, nw.first, true, dis+t[line][i]+nw.second);
						break;
					}
}

int main() {
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _id, n, m, d, _q;
	cin >> _id >> n >> m >> d >> _q;
	vis.resize(m+1); w.resize(m+1); G.resize(m+1);
	a.resize(n+1); t.resize(n+1);
	for(int i = 1; i <= m; ++i)
		cin >> w[i];
	for(int i = 1, k; i <= n; ++i) {
		cin >> k;
		a[i].resize(k+1); t[i].resize(k+1);
		for(int j = 1; j <= k; ++j) {
			cin >> a[i][j] >> t[i][j];
			G[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for(int u, v; _q--; cout.put('\n')) {
		cin >> u >> v;
		ans = 4e18;
		for(const auto& i: G[u]) {
			vis[u] = true;
			dfs(u, v, i.first, false, i.second);
			vis[u] = false;
		}
		cout << ans+w[u]+w[v];
	}
	cout.flush(); return 0;
}