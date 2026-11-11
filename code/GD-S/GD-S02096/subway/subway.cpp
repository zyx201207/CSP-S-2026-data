#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int M=5e5+5,N=505,Q=1e5+5;
int w[M],k[N];
const int maxnode=N+M;
struct edge{
	int v,w;
};
vector<edge> e[2*maxnode];
int vis[2*maxnode],dis[2*maxnode];
int cnt;
inline void dij(int u){
	priority_queue<pair<long long,int>> qp;
	for(int i=0;i<=cnt;i++){
		vis[i]=0;
		dis[i]=1e9;
	}
	qp.push({0,u});
	dis[u]=0;
	while(qp.size()){
		int now=qp.top().second;
		qp.pop();
		if(vis[now]) continue;
		vis[now]=1;
		for(edge next:e[now]){
			if(dis[next.v]>dis[now]+next.w){
				dis[next.v]=dis[now]+next.w;
				qp.push({-dis[next.v],next.v});
			}
		}
	}
}
int dist[1005][1005];
int ac[480][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cnt=n+m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,w;
			cin>>v>>w;
			e[i].push_back({n+v,w});
			e[n+v].push_back({i,w});
		}
	}
	if(9<=c&&c<=11){
		for(int i=1;i<=m;i++){
			dij(n+i);
			for(int j=1;j<=m;j++) dist[i][j]=dis[j+n];
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<dist[x][y]+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	if(c>=12){
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=m;j++){
				ac[i][j]=dis[n+j];
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			int ans=1e9;
			for(int j=1;j<=n;j++){
				ans=min(ans,ac[j][x]+ac[j][y]+w[x]+w[y]);
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dij(n+x);
		cout<<dis[y+n]+w[x]+w[y]<<"\n";
	}
	return 0;
}
