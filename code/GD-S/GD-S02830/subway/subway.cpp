#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505,maxm=500005,maxd=25;
struct st{
	int v,w;
	bool operator<(const st &a)const{
		return w>a.w;
	}
};
vector<st>g[maxn];
int c,n,m,d,q;
int w[maxn],k[maxn];
int vis[maxn][maxn],dis[maxn][maxn],last[maxn][maxn],in[maxm][maxd];
vector<st>station[maxm];
priority_queue<st>pq;
void dijkstra(int s){
	while(pq.size()) pq.pop();
	pq.push({s,0});
	dis[s][s]=0;
	while(pq.size()){
		int u=pq.top().v;
		pq.pop();
		if(vis[s][u]) continue;
		vis[s][u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				pq.push({v,dis[s][v]});
				last[s][v]=v;
			}
		}
	}
}
int solve(int x,int y){
	int ans=0x3f3f3f3f;
	for(auto xx:station[x]){
		for(auto yy:station[y]){
			ans=min(ans,dis[xx.v][yy.v]+in[x][last[yy.v][xx.v]]+in[y][last[xx.v][yy.v]]);
			if(xx.v==yy.v) return in[x][xx.v]+in[y][xx.v]+w[x]+w[y];
		}
	}
	return ans+w[x]+w[y];
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			station[x].push_back({i,y});
			in[x][i]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:station[i]){
			for(auto y:station[i]){
				g[x.v].push_back({y.v,x.w+y.w});
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<'\n';
	}
	return 0;
}
