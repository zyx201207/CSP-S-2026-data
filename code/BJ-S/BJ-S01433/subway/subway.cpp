#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
const long long INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
vector<pair<int,int>> tmp[M];
int w[M];
long long dis[N][N];
vector<pair<int,long long>> vec[N];
priority_queue<pair<long long,int>>pq;
bool vis[N];
void dij(int s){
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++){
		vis[i]=0;
		if(dis[s][i]!=INF) pq.push({dis[s][i],i});
	}
	vis[s]=1;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto t:vec[u]){
			int v=t.first;
			long long w=t.second;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				pq.push({dis[s][v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int k,u,w;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&u,&w);
			for(auto t:tmp[u]){
				int v=t.first;
				dis[i][v]=dis[v][i]=min(dis[i][v],0ll+t.second+w);
			}
			tmp[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(dis[i][j]==INF) continue;
			vec[i].push_back({j,dis[i][j]});
			vec[j].push_back({i,dis[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		int x,y;
		long long ans=INF;
		scanf("%d%d",&x,&y);
		for(auto i:tmp[x])
			for(auto j:tmp[y])
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}