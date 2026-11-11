#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int c,m,n,d,q,w[500005],dist[1005][1005];
vector<pii>roads[500];
vector<int>g[1005];
bool vis[1005],bfsed[1005];
void bfs(int start){
	memset(vis,0,sizeof vis);
	queue<pii>q;
	q.push({start,0});
	vis[start]=1;
	while(!q.empty()){
		int now=q.front().fi,di=q.front().se;
		q.pop();
		for(auto i:g[now]){
			if(vis[i])continue;
			q.push({i,di+dist[now][i]});
			dist[start][i]=min(dist[start][i],di+dist[now][i]);
			vis[i]=1;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f3f3f3f,sizeof dist);
	memset(bfsed,0,sizeof bfsed);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int u,v;
			cin>>u>>v;
			for(auto k:roads[i]){
				dist[k.fi][u]=min(dist[k.fi][u],k.se+v);
				dist[u][k.fi]=min(dist[u][k.fi],k.se+v);
			}
			roads[i].push_back({u,v});
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(!bfsed[u])bfs(u);
		cout<<w[u]+w[v]+dist[u][v]<<endl;
	}
	return 0;
}
