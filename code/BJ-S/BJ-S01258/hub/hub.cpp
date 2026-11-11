#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1e6 + 5;
int c, t, n, k, dep[M], mx[M], nmx[M], dis[N][N]; vector <int> e[N]; bool vis[N];
void dfs(int u, int fa, int o) {
	dis[o][u] = dis[o][fa] + 1;
	for(auto v : e[u]) if(v != fa) dfs(v, u, o);
}
void dfs2(int u, int fa, int s) {
	vis[u] = 1;
	for(auto v : e[u]) if(v != fa && ((s >> (v - 1)) & 1)) dfs2(v, u, s);
}
// void dfs3(int u, int fa) {
// 	dep[u] = dep[fa] + 1, mx[u] = 0, nmx[u] = 0;
// 	for(auto v : e[u]) {
// 		if(v == fa) continue ; dfs3(v, u); int l = mx[v] + 1;
// 		if(l > mx[u]) nmx[u] = mx[u], mx[u] = l;
// 		else if(l > nmx[u]) nmx[u] = l;
// 	}
// }
int main() {
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = 1; i < n; i++) { int u, v; scanf("%d%d", &u, &v); e[u].push_back(v); e[v].push_back(u); }
		// if(c == 7) {
		// 	int ans = INT_MAX;
		// 	if(k == 1) {
		// 		dep[1] = -1; dfs3(1, 1);
		// 		for(int i = 1; i <= n; i++) {
		// 			if(mx[i] + dep[i] == mx[1]) ans = min(ans, max(nmx[1] + dep[i], mx[i]));
		// 			else ans = min(ans, max(mx[1] + dep[i], mx[i]));
		// 		}
		// 		printf("%d\n", ans);
		// 		continue ;
		// 	}
		// 	for(int i = 1; i <= n; i++) {
		// 		dep[i] = -1; dfs3(i, i);
		// 		for(int j = 1; j <= n; j++) {
		// 			if(i == j) continue ;
		// 			if(mx[j] + dep[j] == mx[i]) ans = min(ans, max(nmx[i], max(dep[j] - 1, mx[j])));
		// 			else ans = min(ans, max(mx[i], max(dep[j] - 1, mx[j])));
		// 		}
		// 	}
		// 	printf("%d\n", ans);
		// 	continue ;
		// }
		for(int i = 1; i <= n; i++) { dis[i][i] = -1; dfs(i, i, i); }
		int ans = INT_MAX;
		for(int s = 0; s < (1 << n); s++) {
			if(__builtin_popcount(s) > k) continue ;
			for(int i = 1; i <= n; i++) vis[i] = 0; int cnt = 0;
			for(int i = 1; i <= n; i++) if(((s >> (i - 1)) & 1) && !vis[i]) cnt++, dfs2(i, i, s);
			if(cnt > 2) continue ;
			int mx = 0;
			for(int i = 1; i <= n; i++) {
				int mn = INT_MAX;
				for(int j = 1; j <= n; j++)
					if((s >> (j - 1)) & 1) mn = min(mn, dis[i][j]);
				mx = max(mx, mn);
			}
			ans = min(ans, mx);
		}
		printf("%d\n", ans);
	}
	return 0;
}