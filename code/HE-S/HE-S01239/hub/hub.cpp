#include <bits/stdc++.h>
using namespace std;
#define D(a) cout << #a << " : " << a << " "
#define nl cout << "\n"
const int N = 20;
int c,t;
int fa[N];
vector <int> g[N];
int find(int u){
	return (fa[u] == u ? u : fa[u] = find(fa[u]));
}
void merge(int u,int v){
	int fu = find(u),fv = find(v);
	if (fu != fv){
		fa[fu] = fv;
	}
}
int dep[N];
int tmp;
int vis[N];
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1;
	if (vis[u]) tmp = min(tmp,dep[u]);
	for (int v:g[u]){
		if (v == fa) continue;
		dfs(v,u);
	}
}
void solve(){
	int ans = 0x3f3f3f3f;
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<n;i++){
		int u,v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	for (int st=0;st<(1 << n);st++){
		if (__builtin_popcount(st) != k) continue;
		for (int i=1;i<=n;i++) fa[i] = i;
		for (int i=1;i<=n;i++) vis[i] = 0;
		for (int i=1;i<=n;i++){
			if ((st >> (i-1)) & 1) vis[i] = 1;
		}
		for (int i=1;i<=n;i++){
			for (int v:g[i]){
				if (vis[i] && vis[v]){
					merge(i,v);
				}
			}
		}
		int res = 0;
		for (int i=1;i<=n;i++){
			if (vis[i] && fa[i] == i) res ++;
		}
		if (res > 2) continue;
		res = 0;
		for (int i=1;i<=n;i++){
			dep[0] = -1;
			tmp = 0x3f3f3f3f;
			dfs(i,0);
			res = max(res,tmp);
		}
		ans = min(ans,res);
	}
	cout << ans << "\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
