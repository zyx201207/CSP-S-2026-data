#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, inf = 1e9;
int c, t, n, k, head[maxn << 1], fa[maxn], tot, dis[1005][1005];
bool vis[maxn], fl[maxn];
struct edge{
	int u, v;
}e[maxn << 1];
struct nd{
	int to, nxt;
}ed[maxn << 1];
void add(int u, int v){
	ed[++tot] = {v, head[u]};
	head[u] = tot;
}
int find(int x){
	return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if (fx ^ fy) fa[fx] = fy;
}
void init(){
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = inf;
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i < n; i++) dis[e[i].u][e[i].v] = dis[e[i].v][e[i].u] = 1;
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dis[i][k] + dis[k][j] <= dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
}
void dfs(int u, int f){
	if (fl[u] && fl[f]) merge(u, f);
	for (int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to; if (v ^ f) dfs(v, u);
	}
}
void solve(){
	cin >> n >> k; int ans = n;
	for (int i = 1; i <= n * 2; i++) head[i] = 0; tot = 0;
	for (int i = 1; i < n; i++) cin >> e[i].u >> e[i].v, add(e[i].u, e[i].v), add(e[i].v, e[i].u); init();
//	for (int i = 1; i <= n; i++) {for (int j = 1; j <= n; j++) cout << dis[i][j] << ' '; cout << '\n';}
	for (int i = 0; i < (1 << n); i++){
		if (__builtin_popcount(i) != k) continue;
		for (int j = 1; j <= n; j++) fa[j] = j, vis[j] = fl[j] = 0; int cnt = 0;
		for (int j = 1; j <= n; j++) if (i & (1 << j - 1)) fl[j] = 1; dfs(1, 0);
		for (int j = 1; j <= n; j++) if (i & (1 << j - 1)) {int f = find(j); if (!vis[f]) vis[f] = 1, cnt++;}
		if (cnt > 2) continue; int now = 0;
		for (int j = 1; j <= n; j++){
			if (i & (1 << j - 1)) continue; int d = n;
			for (int k = 1; k <= n; k++) if (i & (1 << k - 1)) d = min(d, dis[j][k]); now = max(now, d);
		}ans = min(ans, now);
	}cout << ans << '\n';
}
main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t; while(t--) solve();
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
