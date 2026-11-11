#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,ground[M],dis[N][N];
vector<pair<int,int>>g[N*20+M];
bool vis[N];
void dijkstra(int s){
	priority_queue<pair<int,int>>q;
	memset(dis[s],0x3f,sizeof dis[s]);
	memset(vis,0,sizeof vis);
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.first,w=e.second;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ground[i];
	for(int i=1;i<=n;i++){
		int k,t;
		int last,a;
		cin>>k>>last>>t;
		a=last;
		g[d*i+a].push_back({a,t});
		g[a].push_back({d*i+a,t});
		for(int j=2;j<=k;j++){
			cin>>a>>t;
			g[d*i+a].push_back({d*i+last,0});
			g[d*i+last].push_back({d*i+a,0});
			g[d*i+a].push_back({a,t});
			g[a].push_back({d*i+a,t});
			last=a;
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dijkstra(i);
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+ground[u]+ground[v]<<'\n';
	}
	return 0;
}
