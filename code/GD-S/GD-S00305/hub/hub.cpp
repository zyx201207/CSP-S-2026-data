#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 15;
int n, k, dis[N][N], vis[N];
vector<int> g[N];

void dfs(int st, int u, int pre){
	for(int v: g[u]) if(v != pre){
		dis[st][v] = dis[st][u] + 1;
		dfs(st, v, u);
	}
}

void clr(int u, int pre){
	for(int v: g[u]) if(v != pre && vis[v]){
		clr(v, u);
	}
	vis[u] = 0;
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) g[i].clear();
	for(int i = 1; i < n; i ++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++){
		dis[i][i] = 0; dfs(i, i, 0);
	}
	int ans = 1e18;
	for(int mask = 0; mask < (1 << n); mask ++){
		if(__builtin_popcountll(mask) != k) continue;
		for(int i = 1; i <= n; i ++){
			vis[i] = ((mask >> (i - 1)) & 1);
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++){
			if(vis[i]) clr(i, 0), cnt ++;
		}
		if(cnt > 2) continue;
		int res = 0;
		for(int i = 1; i <= n; i ++){
			int cur = 1e18;
			for(int j = 1; j <= n; j ++){
				if((mask >> (j - 1)) & 1) cur = min(cur, dis[i][j]);
			}
			res = max(res, cur);
		}
		ans = min(ans, res);
	}
	cout << ans << "\n";
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	int c, t; cin >> c >> t;
	while(t --){
		if(c <= 3) solve();
	}
	
	return 0;
}

