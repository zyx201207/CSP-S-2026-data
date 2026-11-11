#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e17;
int ans,n,m,c,d,qq,a[500005],dis[505][505],vis[505][505],k,x,t,u,v,w;
struct node{
	int v,w;
	bool operator <(node a) const{
		return w>a.w;
	}
}; 
vector<node> h[500005],g[505];
priority_queue<node> q;
void dijkstra(int x){
	dis[x][x]=0;
	q.push({x,dis[x][x]});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[x][u])continue;
		vis[x][u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(dis[x][u]+w<dis[x][v]){
				dis[x][v]=dis[x][u]+w;
				q.push({v,dis[x][v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>x>>t;
			h[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<h[i].size();j++){
			for(int l=j+1;l<h[i].size();l++){
				u=h[i][j].v,v=h[i][l].v,w=h[i][j].w+h[i][l].w;
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			} 
		}
	}
	memset(dis,127,sizeof(dis));
	for(int i=1;i<=n;i++)dijkstra(i);
	while(qq--){
		cin>>u>>v;
		ans=INF;
		for(int i=0;i<h[u].size();i++){
			for(int j=0;j<h[v].size();j++){
				int uu,vv;
				uu=h[u][i].v,vv=h[v][j].v;
				ans=min(ans,a[u]+h[u][i].w+a[v]+h[v][j].w+dis[uu][vv]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 3 7 20 1 
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
*/
