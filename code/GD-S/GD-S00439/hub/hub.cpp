#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int n, k;
vector<int> g[N];
bool vis[N];
int f[N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return;
	f[u] = v;
}
int dis[N];
void dfs(int u) {
	for(auto v : g[u]) if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, dfs(v);
}
void subtask1() {
	int ans = 1e9;
	for(int i = 0; i < (1 << n); i++) {
		if(__builtin_popcount(i) != k) continue;
		for(int j = 1; j <= n; j++) vis[j] = 0, f[j] = j, dis[j] = 1e9;
		for(int j = 1; j <= n; j++) if(i >> (j - 1) & 1) vis[j] = 1, dis[j] = 0;
		for(int j = 1; j <= n; j++) if(vis[j])
			for(auto v : g[j]) if(vis[v]) merge(j, v);
		int c1 = 0, c2 = 0;
		bool fl = 1;
		for(int j = 1; j <= n; j++) if(vis[j]) {
			if(c1 == 0) c1 = find(j);
			else if(c1 != find(j) && c2 == 0) c2 = find(j);
			else if(c1 != find(j) && c2 != find(j)) {fl = 0; break;}
		}
		if(fl) {
			for(int j = 1; j <= n; j++) if(vis[j]) dfs(j);
			int res = 0;
			for(int j = 1; j <= n; j++) if(!vis[j]) res = max(res, dis[j]);
			ans = min(ans, res); 
		}
	}
	printf("%d\n", ans);
}
void solve() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	subtask1();
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int Ca, T; scanf("%d%d", &Ca, &T);
	while(T--) solve();
	return 0;
}

