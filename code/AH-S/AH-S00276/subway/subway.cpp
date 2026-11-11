#include<bits/stdc++.h>
using namespace std;
void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
#define int long long
const int N=1e5+10;
vector<pair<int,int>> adj[N];
int w[N],vis[N];
int c,n,m,d,q;
int ans=LONG_LONG_MAX;
void dfs(int u,int z,int& ret){
	if(u==z){
		ans=min(ret,ans);
		return;
	}
	if(ret>ans) return;
	for(auto& x:adj[u]){
		int v=x.first,t=x.second;
		if(vis[v]==1) continue;
		ret+=t;
		vis[v]=1;
		dfs(v,z,ret);
		vis[v]=0;
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			adj[i].push_back({a,t});
			adj[a].push_back({i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ret=0;
		dfs(x,y,ret);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return;
}
