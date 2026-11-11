#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int INF=0X3f3f3f;
int c,n,m,d,q;
int w[M];
int t[M][22];
int dis[M];
bool vis[M];
struct node{
	int id;
	int wealth;
};
bool operator<(const node a,const node b){
	return a.wealth>b.wealth;
}
vector<node> g[M];
vector<int> path[510];
void dijkstra(int start){
	fill(dis,dis+M,INF);
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({start,0});
	dis[start]=0;
	while(!q.empty()){
		node cur=q.top();
		q.pop();
		int u=cur.id;
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].id;
			int	dm=g[u][i].wealth;
			if(!vis[v]&&dis[v]>dis[u]+dm){
				dis[v]=dis[u]+dm;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x;
			cin>>x;
			path[i].push_back(x);
			cin>>t[x][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=path[i].size();j++){
			int u=path[i][j-1];
			int v=path[i][j];
			int d=t[u][i]+t[v][i];
			g[u].push_back({v,d});
			g[v].push_back({u,d});
		}
	}
	while(q--){
		int start,end;
		cin>>start>>end;
		dijkstra(start);
		int ans=w[start]+dis[end]+w[end];
        cout<<ans<<endl;
	}
	return 0;
}