#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, k;
vector<int> g[N];
const int LOG = 20;
int f[LOG][N];
int dep[N];
bool vis[N];

inline void dfs1(int u, int fa){
	f[0][u] = fa;
	dep[u] = dep[fa] + 1;
	for(int i = 1;(1 << i) <= dep[u];i ++){
		f[i][u] = f[i - 1][f[i - 1][u]];
	}
	for(int &v : g[u]){
		if(v == fa) continue;
		dfs1(v, u);
	}
}

inline int lca(int u, int v){
	if(u == v) return u;
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 19;i >= 0;i --){
		if(dep[f[i][u]] <= dep[v]){
			u = f[i][u];
		}
	}
	if(u == v) return u;
	for(int i = 19;i >= 0;i --){
		if(f[i][u] != f[i][v]){
			u = f[i][u];
			v = f[i][v];
		}
	}
	return f[0][u];
}

inline int dis(int u, int v){
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

bool v[N];
inline void dfs(int u){
	if(v[u]) return;
	v[u] = 1;
	for(int &v : g[u]){
		if(vis[v]){
			dfs(v);
		}
	}
}

inline void solve(){
	cin >> n >> k;
	for(int i = 1;i < n;i ++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	int ans = 0;
	for(int msk = 0;msk < (1 << n);msk ++){
		int cnt = 0;
		for(int i = n - 1;i >= 0;i --){
			vis[i + 1] = (msk >> i) & 1;
			if((msk >> i) & 1) cnt ++;
		}
		if(cnt != k) continue;
		int sz = 0;
		for(int i = 1;i <= n;i ++) v[i] = 0;
		for(int i = 1;i <= n;i ++){
			if(vis[i] && !v[i]){
				sz ++;
				dfs(i);
			}
		}
		if(sz > 2) continue;
		for(int i = 1;i <= n;i ++){
			int mn = 1e9;
			for(int j = 1;j <= n;j ++){
				if(vis[j]) mn = min(mn, dis(i, j));
			}
			ans = max(ans, mn);
		}
	}
	cout << ans << '\n';
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	int c, T = 1;
	cin >> c >> T;
	while(T --)	solve();
	return 0;
}
