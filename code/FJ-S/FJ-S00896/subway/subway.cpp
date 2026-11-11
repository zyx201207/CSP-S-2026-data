#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,w[500005],k,t[500005][505],x,y;
set<int> g[505];
unordered_set<int> lne[500005];
bool vis[505],goal[505];
long long ans=LLONG_MAX,chgt[505][505];
//struct edge{
//	int u,v;
//	bool operator>(const edge &o)const{
//		return chgt[u][v]>chgt[o.u][o.v];
//	}
//};
void dfs(int u,long long time){
//	cout<<u<<" "<<time<<"\n";
	if(goal[u]){
		ans=min(ans,time+t[y][u]);
		return;
	}
	for(int v:g[u]){
		if(vis[v]) continue;
		vis[v]=1;
		dfs(v,time+chgt[u][v]);
	}
}
//long long dijkstra(long long time){
//	long long ans=LLONG_MAX;
//	memset(dis,0x3f,sizeof(dis));
//	dis[x]=time;
//	f[x]=1;
//	priority_queue<edge,vector<edge>,greater<edge>> q;
//	for(int v:g[x]) q.push({x,v});
//	while(!q.empty()){
//		edge e=q.top();q.pop();
//		if(f[e.v]) continue;
//		f[e.v]=1;
//		if(dis[e.v]>dis[e.u]+chgt[e.u][e.v])
//			dis[e.v]=dis[e.u]+chgt[e.u][e.v];
//		for(int v:g[e.v]){
//			if(dis[v]>dis[e.v]+chgt[e.v][v]){
//				dis[v]=dis[e.v]+chgt[e.v][v];
//			}
//			q.push({e.v,v});
//		}
//	}
//	for(int i:lne[y]) ans=min(ans,dis[i]+t[y][i]);
//	return ans;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(chgt,0x3f,sizeof(chgt));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		chgt[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x;
			cin>>t[x][i];
			lne[x].insert(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j:lne[i]){
			for(int k:lne[i]){
				g[j].insert(k);
				g[k].insert(j);
				chgt[j][k]=chgt[k][j]=min(chgt[j][k],(long long)t[i][j]+t[i][k]);
			}
		}
	}
	while(q--){
		ans=LLONG_MAX;
		memset(goal,0,sizeof(goal));
		cin>>x>>y;
		for(int i:lne[y]) goal[i]=1;
		for(int i:lne[x]){
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(i,t[x][i]);
//			ans=min(ans,dijkstra(t[x][i]));
//			for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//			cout<<"\n";
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}

