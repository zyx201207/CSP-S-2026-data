#include<bits/stdc++.h>
#define int long long
#define fst first
#define scd second
#define pb push_back
using namespace std;
const int N=5e5+600,inf=1e18;
int c,n,m,d,Q;
int w[N];
vector<pair<int,int> >G[N];
int dis[N],vis[N],fa[N];
vector<int>T[N];
int dep[N],lg2[N],f[N][18];
void dfs(int u,int fa){
	vis[u]=1;
	for(auto v:T[u]){
		if(v!=fa){
			dep[v]=dep[u]+1;
			dfs(v,u);
		}
	}
	vis[u]=0;
}
int lca(int x,int y){
	while(dep[x]<dep[y]){
		y=f[y][lg2[dep[y]-dep[x]+1]];
	}
	if(x==y)return x;
	int i;
	for(i=0;i<=dep[x];i++)
		if(f[x][0]!=f[y][0])x=f[x][0],y=f[y][0];
		else break;
	return f[x][0];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1,k;i<=m;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			G[a].pb({i+n,t});
			G[i+n].pb({a,t});
		}
	}
	for(int i=1;i<=n+m;i++)fa[i]=i,dis[i]=inf;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,1});dis[1]=0;
	while(!q.empty()){
		int u=q.top().scd;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
				fa[v]=u;
			}
		}
	}
	for(int i=2;i<=n+m;i++){
		T[i].pb(fa[i]);
		T[fa[i]].pb(i);
		vis[i]=0;
	}
	dfs(1,1);
	for(int i=2;i<N;i++)lg2[i]=lg2[i/2]+1;
	for(int i=1;i<=n+m;i++)f[i][0]=fa[i];
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=17;j++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(int i=1,x,y;i<=Q;i++){
		cin>>x>>y;
		if(dep[y]<dep[x])swap(x,y);
		cout<<w[x]+w[y]+dis[x]+dis[y]-2*dis[lca(x,y)]<<'\n';
	}
	
	return 0;
}