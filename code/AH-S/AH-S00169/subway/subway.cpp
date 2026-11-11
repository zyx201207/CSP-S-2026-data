#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
const int MAXN=5e5+600,LOG=21;
int c,n,m,d,q,w[MAXN],k;
struct edge{ int to,w; };
vector<edge> e[MAXN];
int dis[MAXN],dep[MAXN],fa[MAXN][LOG],DIS[MAXN];
int vis[MAXN];
map<int,int> mp[MAXN];
bool st[MAXN];
void dijkstra(int s){
	memset(st,0,sizeof st);
	for(int i=1;i<=n+m;i++) dis[i]=1e18;
	priority_queue<P,vector<P>,greater<P>> q;
	P p;p.first=0,p.second=s;
	q.push(p);
	dis[s]=0;
	while(!q.empty()){
		P now=q.top();
		q.pop();
		int w=now.first,t=now.second;
		if(w>dis[t]||st[t]) continue;
		st[t]=1;
		for(int i=0;i<e[t].size();i++){
			int to=e[t][i].to,w=e[t][i].w;
			if(dis[to]>dis[t]+w){
				dis[to]=dis[t]+w;
				P g;g.first=dis[to],g.second=to;
				q.push(g);
			}
		}
	}
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<LOG;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=0;i<e[x].size();i++){
		int to=e[x][i].to,w=e[x][i].w;
		if(to==f) continue;
		DIS[to]=DIS[x]+w;
		dfs(to,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=LOG-1;i>=0;i--){
		if((d>>i)&1) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=LOG-1;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	bool f=1;
	for(int u=1;u<=m;u++){
		scanf("%lld",&k);
		if(k>2) f=0;
		for(int j=1;j<=k;j++){
			int v,w;
			scanf("%lld%lld",&v,&w);
			e[n+u].push_back({v,w});
			e[v].push_back({n+u,w});
		}
	}
	if(f) dfs(1,0);	
	while(q--){
		int x,y,ans;
		scanf("%lld%lld",&x,&y);
		if(f) printf("%lld\n",DIS[x]+DIS[y]-2*DIS[lca(x,y)]+w[x]+w[y]);
		if(vis[x]) ans=mp[x][y];
		else{
			dijkstra(x);
			ans=dis[y];
			vis[x]=1;
			for(int i=1;i<=n+m;i++) mp[x][i]=dis[i];
		}
		if(!f) printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
