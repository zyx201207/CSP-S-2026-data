#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x;
	cin >> x;
	return x;
}
const int N = 1000005;
int n, k;
struct SON{
	int ver, nxt;
}o[N << 1];
int tot, head[N];
inline void add_edge(int u, int v){
	o[++tot] = SON{v, head[u]};
	head[u] = tot;
}
struct DSU{
	int f[N], sz[N];
	inline void init(){
		for(int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
	}
	int getf(int u){
		return f[u] == u ? u : f[u] = getf(f[u]);
	}
	inline void merge(int u, int v){
		u = getf(u), v = getf(v);
		if(u ^ v){
			if(sz[u] > sz[v]) u ^= v, v ^= u, u ^= v;
			f[u] = v, sz[v] += sz[u];
		}
	}
}dsu;
bool flag[N];
int dis[N];
bool vis[N];
inline void BFS(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		dis[i] = n, vis[i] = false;
		if(flag[i]){
			dis[i] = 0;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = o[i].nxt){
			int v = o[i].ver;
			if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.push(v);
		}
	}
}
inline void solve_A(){
	int ans = n;
	for(int S = 0; S < (1 << n); S++)
		if(__builtin_popcount(S) == k){
			dsu.init();
			for(int u = 1; u <= n; u++)
				if(S >> (u - 1) & 1) flag[u] = true;
				else flag[u] = false;
			for(int u = 1; u <= n; u++)
				if(flag[u])
					for(int i = head[u]; i; i = o[i].nxt){
						int v = o[i].ver;
						if(flag[v]) dsu.merge(u, v);
					}
			set<int> s;
			for(int u = 1; u <= n; u++)
				if(flag[u])
					s.insert(dsu.getf(u));
			if(s.size() > 2) continue;
			BFS();
			int res = 0;
			for(int i = 1; i <= n; i++) res = max(res, dis[i]);
			ans = min(ans, res);
		}
	cout << ans << '\n';
}
inline void solve(){
	n = read(), k = read(), tot = 0;
	for(int i = 1; i <= n; i++) head[i] = 0;
	for(int i = 1; i < n; i++){
		int u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
	}
	if(n <= 10) solve_A();
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(int test = read(), T = read(); T; T--) solve();
	return 0;
}
