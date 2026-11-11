#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+600+10;
int w[N],CNT,n,m,D,Q;
int head[N],ver[N<<1],net[N<<1],edge[N<<1],tot; 
inline void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;net[tot]=head[x];head[x]=tot;
}int dist[N];bool vis[N];
priority_queue<pair<int,int> > q;
inline void dijkstra(int st){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while(q.size())q.pop();
	q.push({0,st});dist[st]=0;
	while(q.size()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=net[i]){
			int y=ver[i],z=edge[i];
			if(dist[y]>dist[x]+z){
				dist[y]=dist[x]+z;
				q.push({-dist[y],y});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>CNT>>m>>n>>D>>Q;
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}for(int i=1;i<=m;++i){
		int ns;
		cin>>ns;int nw=n+i; 
		for(int j=1;j<=ns;++j){
			int y,cost;cin>>y>>cost;
			add(nw,y,cost);add(y,nw,cost);
		}
	}for(int i=1;i<=Q;++i){
		int x,y;cin>>x>>y;
		dijkstra(x);
		cout<<dist[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
