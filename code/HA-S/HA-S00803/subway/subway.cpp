#include<bits/stdc++.h>
#define int long long
#define pll pair<long long,long long>
using namespace std;
int c,n,m,d,Q,w[500005],dis[1505][1505],dist[20505],sumk;
struct node{
	int v,val;
};
vector<node>G[600005];
bool vis[1505];
priority_queue<pll,vector<pll>,greater<pll> >q;
void dijkstra(int st){
	memset(vis,0,sizeof(vis));
	dis[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:G[u]){
			if(dis[st][v.v]>dis[st][u]+v.val){
				dis[st][v.v]=dis[st][u]+v.val;
				q.push({dis[st][v.v],v.v});
			}
		}
	}
}
bool visbfs[20505];
queue<int>q2;
void bfs(int st){
	for(int i=1;i<=n+sumk;i++){
		visbfs[i]=0;
		dist[i]=1e18;
	}
	q2.push(st);
	dist[st]=0;
	while(!q2.empty()){
		int u=q2.front();
		q2.pop();
		if(visbfs[u])continue;
		visbfs[u]=1;
		for(auto v:G[u]){
			if(dist[v.v]>dist[u]+1){
				dist[v.v]=dist[u]+1;
				q2.push(v.v);
			}
		}
	}
}
#undef int
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#define int long long
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	int T=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		sumk+=k;
		for(int j=1;j<=k;j++){
			int x,val;
			scanf("%lld%lld",&x,&val);
			T=val;
			G[i+m].push_back({x,val});
			G[x].push_back({i+m,val});
		}
	}
	if(sumk<=1000){
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;i++)dijkstra(i);
		while(Q--){
			int st,ed;
			scanf("%lld%lld",&st,&ed);
			printf("%lld\n",dis[st][ed]+w[st]+w[ed]);
		}
	}
	else{
		while(Q--){
			int st,ed;
			scanf("%lld%lld",&st,&ed);
			bfs(st);
			printf("%lld\n",dist[ed]*T+w[st]+w[ed]);
		}
	}
	return 0;
}
