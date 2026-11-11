#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10; 
int c,t,n,k,up[maxn][22],dep[maxn],ans=INT_MAX;
vector<int> G[maxn];
bool vis[maxn];
void dfs(int u,int fa) {
	dep[u] = dep[fa] + 1;
	up[u][0] = fa;
	for(int v : G[u]) {
		if(v == fa) continue;
		dfs(v,u);
	}
}
void init(){
	for(int j = 1;j <= 20;j++) {
		for(int i = 1;i <= n;i++) {
			up[i][j] = up[ up[i][j-1] ][j-1];
		}
	}
}
int lca(int u,int v) {
	if(dep[u] > dep[v]) swap(u,v);
	for(int i = 20;i >= 0;i--) {
		if(dep[v] - (1 << i) >= dep[u]) {
			v = up[v][i];
		}
	}if(v == u) return v;
	for(int i = 20;i>=0;i--) {
		if(up[u][i]!=up[v][i]) {
			u=up[u][i]; v=up[v][i];
		}
	}return up[u][0];
}
int dist(int u,int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u,v)];
}vector<int> sl;
void check(int u,int fa) {
	for(int v : G[u]) {
		if(!vis[v] && find(sl.begin(),sl.end(),v)!=sl.end()){
			vis[v] =  1;
			check(v,u);
		}
	}
}

void DFS(int dep) {
	if(sl.size() == k) {
		memset(vis,0,sizeof(vis));
		vis[sl[0]]=1;
		check(sl[0],sl[0]);
		int idx = -1;
		for(int i = 0;i < sl.size();i++) {
			if(!vis[sl[i]]){
				idx=sl[i];
				break;
			}
		}vis[idx]=1;
		check(idx,idx);
		for(int i=0;i<sl.size();i++)if(!vis[sl[i]])return;
		int mx=0;
		for(int i = 1;i <= n;i++) {
			int ps = INT_MAX;
			for(int j = 0;j < sl.size();j++) {
				ps = min(ps,dist(sl[j],i));
			}mx=max(mx,ps);
		}ans = min(mx,ans);
		return ;
	}if(dep == n + 1) return ;
	DFS(dep+1);
	sl.push_back(dep);
	DFS(dep);
	sl.pop_back();
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		ans = INT_MAX;
		cin >> n >> k;
		for(int i = 1;i <=n;i++) G[i].clear();
		for(int i = 1,u,v;i < n;i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}dfs(1,1); init();
		DFS(1);
		cout<<ans<<'\n';
	}
	return 0;
} 
