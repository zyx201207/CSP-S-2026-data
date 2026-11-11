#include<bits/stdc++.h>
using namespace std;
const int N=510,K=5e5+10;
long long C,n,m,d,Q;
long long w[K],line[K],ti[K];
long long dis[3*K],vis[3*K];
bool f[K];
struct stu{
	long long v,w;
};
vector<stu> g[K];
long long dijkstra(long long s,long long t){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		long long u=q.top().second;
		q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			long long v=g[u][i].v,w=g[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		} 
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i+m].push_back({i+2*m,w[i]});
		g[i+2*m].push_back({i+m,w[i]});
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>line[j]>>ti[j];
		for(int j=1;j<=k-1;j++){
			if(f[line[j]]==1){
				g[line[j-1]].push_back({line[j+1],0});
				g[line[j+1]].push_back({line[j-1],0});
				g[line[j-1]].push_back({line[j]+m,ti[j]});
				g[line[j]+m].push_back({line[j-1],ti[j]});
				g[line[j+1]].push_back({line[j]+m,ti[j]});
				g[line[j]+m].push_back({line[j+1],ti[j]});
			}else{
				g[line[j]].push_back({line[j+1],0});
				g[line[j+1]].push_back({line[j],0});
			}
			g[line[j]].push_back({line[j]+m,ti[j]});
			g[line[j]+m].push_back({line[j],ti[j]});
		}
		g[line[k]].push_back({line[k]+m,ti[k]});
		g[line[k]+m].push_back({line[k],ti[k]});
		for(int j=1;j<=k;j++) f[line[j]]=1;
	}
	while(Q--){
		long long x,y;
		cin>>x>>y;
		cout<<dijkstra(x+2*m,y+2*m)<<"\n";
	}
	return 0;
}
