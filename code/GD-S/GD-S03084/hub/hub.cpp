#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=1e6,LOGN=20,INF=0x3f3f3f3f3f3f3f3f;
int n,k;
vector<int> adj[MAXN+5];
int dep[MAXN+5];
int up[MAXN+5][LOGN+5];

void init(int u,int pa){
	dep[u]=dep[up[u][0]]+1;
	up[u][0]=pa;
	for(int i=1;i<=LOGN;++i) up[u][i]=up[up[u][i-1]][i-1];
	for(int v:adj[u]){
		if(v==pa) continue;
		init(v,u);
	}
}

int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=0;i<=LOGN;++i) if(dep[u]-dep[v]&1<<i) u=up[u][i];
	if(u==v) return u;
	for(int i=LOGN;i>=0;--i) if(up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
	return up[u][0];
}

vector<int> sol;
int dfs(int u,int cnt,bool con){
	if(cnt==k){
		int res=0;
		for(int i=1;i<=n;++i){
			if(find(sol.begin(),sol.end(),i)!=sol.end()) continue;
			int d=INF;
			for(int j:sol) d=min(d,dep[i]+dep[j]-2*dep[lca(i,j)]);
			res=max(res,d);
		}
		return res;
	}
	int res=INF;
	for(int v=u+1;v<=n;++v){
		bool f=false;
		for(int w:adj[v]) if(sol.empty()||find(sol.begin(),sol.end(),w)!=sol.end()) f=true;
		if(!con&&!f) continue;
		sol.push_back(v);
		res=min(res,dfs(v,cnt+1,con&&f));
		sol.pop_back();
	}
	return res;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v; cin>>u>>v;
		adj[u].push_back(v),adj[v].push_back(u);
	}
	init(1,0);
	cout<<dfs(0,0,true)<<"\n";
}

signed main(){
	freopen("hub1.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
}
