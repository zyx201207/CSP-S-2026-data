#include <bits/stdc++.h>
#define ll long long
using namespace std;
using pii=pair<ll,ll>;
const int nmax=5e5+5+505;
vector<pii> g[nmax];
ll a[nmax];
ll depth[nmax];
ll fa[nmax][19];
void dfs_lca(int u,int p){
	fa[u][0]=p;
	for(int i=1;i<=18;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(auto e:g[u]){
		ll w=e.first,v=e.second;
		if(v==p) continue;
		depth[v]=depth[u]+w;
		dfs_lca(v,u);
	}
}
int lca(int u,int v){
	if(depth[v]>depth[u]) swap(u,v);
	for(int i=18;i>=0;i--){
		if(depth[fa[u][i]]>=depth[v]){
			u=fa[u][i];
		}
	}
	if(u==v) return u;
	for(int i=18;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,lim,q;
	cin>>c>>n>>m>>lim>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=i+m;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll y,w;
			cin>>y>>w;
			g[x].push_back({w,y});
			g[y].push_back({w,x});
		}
	}
	for(int i=1;i<=n+m;i++){
		if(!depth[i]){
			dfs_lca(i,0);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int p=lca(x,y);
		ll ans=depth[x]+depth[y]-2*depth[fa[p][0]];
		ans+=a[x]+a[y];
		cout<<ans<<"\n"; 
	}
	return 0;
}
