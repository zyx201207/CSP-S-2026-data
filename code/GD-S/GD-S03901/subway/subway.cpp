#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=6e5+5;
const int N=505;
int c,n,m,d,q;
int w[M];
int k[N];
struct edge{
	int v,w;
};
vector<edge>e[M];
int tot;
int dis[M];
int vis[M];
priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > qq;
int dij(int s,int t){
	for(int i=1;i<=tot;i++)dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	qq.push({0,s});
	while(qq.size()){
		int u=qq.top().second;
		qq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto ed:e[u]){
			int v=ed.v;
			if(dis[u]+ed.w<dis[v]){
				dis[v]=ed.w+dis[u];
				qq.push({dis[v],v});
			}
		}
	}
	return dis[t];
}
queue<int>qqq;
int bfs(int s,int t){
	while(qqq.size())qqq.pop();
	qqq.push(s);
	for(int i=1;i<=tot;i++)vis[i]=0,dis[i]=1e18;
	dis[s]=0;
	vis[s]=1;
	while(qqq.size()){
		int u=qqq.front();
		qqq.pop();
		if(u==t){
			return dis[t];
		}
		for(auto ed:e[u]){
			int ww=ed.w;
			int v=ed.v;
			if(!vis[v]){
				vis[v]=1;
				qqq.push(v);
				dis[v]=dis[u]+ww;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	tot=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		tot++;
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
			e[tot].push_back({x,t});
			e[x].push_back({tot,t}); 
		}
	}
	if(c>=12&&c<=15){
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<bfs(u,v)+w[u]+w[v]<<'\n';
		}
		return 0;
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dij(u,v)+w[u]+w[v]<<'\n';
	}
	return 0;
}
