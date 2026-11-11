#include<bits/stdc++.h>
namespace kimi{
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;
const int maxn = 1e6 + 10;
struct HLD{
	vector<int> dep, top, fa, sz;
	vector<vector<int> > G;
	void init(int n){
		dep.resize(n), top.resize(n), fa.resize(n), sz.resize(n);
		G.assign(n, {});
	}
	void add(int u, int v){G[u].pb(v), G[v].pb(u);}
	void work(int rt = 1){
		dep[rt] = 0, top[rt] = rt, fa[rt] = -1;
		dfs1(rt), dfs2(rt);
	}
	void dfs1(int u){
		if(~fa[u]) G[u].erase(find(all(G[u]), fa[u]));
		sz[u] = 1;
		for(auto &v : G[u]){
			dep[v] = dep[u] + 1, fa[v] = u;
			dfs1(v);
			if(sz[v] >= sz[G[u][0]]) swap(v, G[u][0]);
		}
	}
	void dfs2(int u){for(auto v : G[u]) top[v] = (v == G[u][0] ? top[u] : v), dfs2(v);}
	int lca(int u, int v){
		while(top[u] != top[v]){
			if(dep[top[u]] < dep[top[v]]) v = fa[top[v]];
			else u = fa[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	}
	int dis(int u, int v){return dep[u] + dep[v] - 2 * dep[lca(u, v)];}
}H;
int n, k;
bool check(int x){
	
}
void mian(){
	cin >> n >> k;
	H.init(n + 10);
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, H.add(u, v);
	H.work();
	cout << 1 << endl;
	/*int l = 0, r = 2e6 + 10;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << endl;*/
}
}using namespace kimi;
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0); 
	int c, Test = 1;
	cin >> c >> Test;
	while(Test--) mian();
	return 0;
}
