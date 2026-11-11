#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace code {
	const int N = 1005;
	int n, m, ans = 1e9, p[N], fa[N], dis[N][N];
	vector<int> g[N];
	bool vis[N];
	
	int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
	
	void dfs(int u, int sta) {
		if(u > m) {
			for(int i = 1; i <= m; i++)
				fa[p[i]] = p[i];
			for(int i = 1; i <= m; i++) {
				for(auto j : g[p[i]])
					if(vis[j]) {
						int fi = find(p[i]), fj = find(j);
						if(fi != fj)
							fa[fi] = fj;
					}
			}
			set<int> s;
			for(int i = 1; i <= m; i++)
				s.insert(find(p[i]));
			if(s.size() > 2)
				return ;
			int piu = 0;
			for(int i = 1; i <= n; i++) {
				int d = 1e9;
				if(vis[i]) 
					d = 0;
				for(int j = 1; j <= m; j++)
					d = min(d, dis[i][p[j]]);
				piu = max(piu, d);
			}
			ans = min(ans, piu);
			return ;
		}
		for(int i = sta; i <= n; i++) {
			p[u] = i;
			vis[i] = true;
			dfs(u + 1, i + 1);
			vis[i] = false;
		}
	}
	
	void dfs2(int u, int rt, int fa) {
		for(auto v : g[u]) {
			if(v == fa)
				continue;
			dis[rt][v] = dis[rt][u] + 1;
			dfs2(v, rt, u);
		}
	}
	
	void solve() {
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		ans = 1e9;
		for(int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i = 1; i <= n; i++) {
			dis[i][i] = 0;
			dfs2(i, i, 0);
		}
		dfs(1, 1);
		cout << ans << '\n';
	}
	
	void niam() {
		int c, t;
		cin >> c >> t;
		while(t--)
			solve();
	}
}

int main() {
#ifndef _NO_FREOPEN_
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	code::niam();
	
	return 0;
}
