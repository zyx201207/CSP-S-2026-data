#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int c, tt;
const int N = 1e6 + 10;
vector <int> G[N];
int f[N][21], dep[N];
void dfs(int now, int fa) {
	f[now][0] = fa;
	dep[now] = dep[fa] + 1;
	for (int i = 1; i <= 20; i ++) f[now][i] = f[f[now][i - 1]][i - 1];
	for (auto u : G[now]) {
		if(u == fa) continue;
		dfs(u, now);
	}
}
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	int del = dep[x] - dep[y];
	for (int i = 0; i < 21; i ++) {
		if((del >> i) & 1) {
			x = f[x][i];
		}
	}
	if(x == y) return x;
	for (int i = 20; i >= 0; i --) {
		if(f[x][i] != f[y][i]) {
			x = f[x][i], y = f[y][i];
		}
	}
	return f[x][0];
}
int vis[N];
void solve(int now, int msk) {
	vis[now] = 1;
	for (auto u : G[now]) {
		if(vis[u] || (!((msk >> (u - 1)) & 1))) continue ;
		solve(u, msk); 
	}
}
int dis[1005][1005], mx[N];
signed main(void) {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> tt;
	while (tt --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) G[i].clear();
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		int ans = 1e18;
		for (int msk = 0; msk < (1ll << n); msk ++) {
			int pc = __builtin_popcountll(msk);
			if(pc == k) {
				int res = 0;
				for (int i = 1; i <= n; i ++) vis[i] = 0;
				int cnt = 0;
				for (int i = 1; i <= n; i ++) {
					if((msk >> (i - 1)) & 1) {
						if(!vis[i]) {
							cnt ++;
							solve(i, msk);
						}
					}
				}
				if(cnt && cnt <= 2) {
					int res = 0;
					for (int i = 1; i <= n; i ++) {
						if((msk >> (i - 1)) & 1) continue ;
						int d = 1e18;
						for (int j = 1; j <= n; j ++) {
							if((msk >> (j - 1)) & 1) {
								int l = lca(i, j);
								int nd = dep[i] + dep[j] - 2 * dep[l];
								d = min(d, nd);
							}
						}
						res = max(res, d);
					}
					ans = min(ans, res);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}