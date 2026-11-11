#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+505;
int n,m,Max,p,t0,tot;
int w[maxn];
struct node{
	int to,val;
};
vector <node> g[maxn];
int anc[maxn][24],dep[maxn];
long long dis[maxn];
bool vis[maxn];
void dfs(int u,int fa)
{
	anc[u][0]=fa;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].to,w=g[u][i].val;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dis[v]=(long long)dis[u]+w;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=23;i>=0;i--)
		if(dep[anc[u][i]]>=dep[v]) u=anc[u][i];
	if(u==v) return u;
	for(int i=23;i>=0;i--){
		if(anc[u][i]!=anc[v][i]){
			u=anc[u][i];
			v=anc[v][i];
		}
	}
	return anc[u][0];
}
void init()
{
	for(int i=1;i<=n+m;i++){
		dis[i]=0;
		vis[i]=0;
	} 
}
void dijkstra(int s)
{
	priority_queue <pair<int,int> > q;
	for(int i=1;i<=n+m;i++) dis[i]=1e18;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t0>>m>>n>>Max>>p;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			tot++;
			g[n+i].push_back({x,y});
			g[x].push_back({n+i,y});
		}
	} 
	if(tot==n+m-1){
		dfs(1,0);
		for(int j=23;j>=1;j--)
			for(int i=1;i<=n+m;i++)
				anc[i][j]=anc[anc[i][j-1]][j-1];
		while(p--){
			int x,y;
			cin>>x>>y;
			int fa=lca(x,y);
			long long ans=dis[x]+dis[y]-2*dis[fa]+w[x]+w[y];
			cout<<ans<<"\n";
		}
	}
	else{
		while(p--){
			init();
			int s,e;
			cin>>s>>e;
			dijkstra(s);
			cout<<dis[e]+w[s]+w[e]<<"\n";
		}
	}
	return 0;
}

