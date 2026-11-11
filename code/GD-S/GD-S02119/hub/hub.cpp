#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7, inf = 0x3f3f3f3f;
vector<int> G[maxn], g[maxn];
bool vis[maxn];
int dp1[maxn], dp2[maxn];
void dfs1(int u) {
	vis[u] = 1;
	for(int v : g[u]) {
		if(!vis[v]) dfs1(v);
	}
}
bool check(int n, int S) {
	for(int i = 0; i < n; i++) vis[i] = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(!(S & (1 << i))) continue;
		if(!vis[i]) {
			cnt++;
			dfs1(i);
		}
	}
	return cnt <= 2;
}
void dfs(int u, int f, int d[]) {
	for(int v : G[u]) {
		if(v == f) continue;
		d[v] = d[u] + 1;
		dfs(v, u, d);
	}
}
int solve1(int n, int S) {
	for(int i = 0; i < n; i++) dp1[i] = inf;
	for(int i = 0; i < n; i++) if(S & (1 << i)) {
		dp2[i] = 0;
		dfs(i, i, dp2);
		for(int k = 0; k < n; k++) dp1[k] = min(dp1[k], dp2[k]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dp1[i]);
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		for(int i = 0; i < n; i++) G[i].clear();
		
		for(int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		if(c <= 3) {
			int all = (1 << n) - 1, ans = inf;
			for(int S = 1; S <= all; S++) {
				if(__builtin_popcount(S) > k) continue;
				for(int i = 0; i < n; i++) g[i].clear();
				for(int i = 0; i < n; i++) {
					if(!(S & (1 << i))) continue;
					for(int j : G[i]) if(S & (1 << j)) g[i].push_back(j);
				}
				if(!check(n, S)) continue;
				ans = min(ans, solve1(n, S));
			}
			cout << ans << "\n";
		}
		else {
			int ans = inf;
			for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
				dp1[i] = 0, dp2[j] = 0;
				dfs(i, i, dp1); dfs(j, j, dp2);
				int ret = 0;
				for(int k = 0; k < n; k++) ret = max(ret, min(dp1[k], dp2[k]));
				ans = min(ans, ret);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
