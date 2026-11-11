#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
ll c,n,m,d,q;
ll w[N],k;
struct node{
	ll a,t;
}e[N];
struct edge{
	ll v,w;
};
vector<edge>g[N],gg[N];
ll dis[550][550];
priority_queue<pair<ll,ll> >qq;
bool vis[5500];
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		dis[s][i]=1e18;
		vis[i]=0;
	}
	dis[s][s]=0;
	while(!qq.empty()) qq.pop();
	qq.push({0,s});
	while(!qq.empty()){
		int u=qq.top().second;
		qq.pop();
		vis[u]=1;
		for(auto o:g[u]){
			int v=o.v;
			int w=o.w;
			if(vis[v]) continue;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				qq.push({-dis[s][v],v});
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
	ll cc=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>e[j].a>>e[j].t;
			if(!cc) cc=e[j].t;
			if(e[j].t!=cc) flag=false;
		}
		if(k==2){
			g[e[1].a].push_back({e[2].a,e[1].t+e[2].t});
			g[e[2].a].push_back({e[1].a,e[1].t+e[2].t});
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]<<'\n';
	}
	return 0;
}
