#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=5e5+25;
ll c,n,m,d,q;
ll dis[3*M];
ll memo[3001][3001];
bool vis[3*M];
struct node{
	ll vv,ww;
	bool operator<(const node &x)const{
		return x.ww<ww;
	}
};
struct edge{
	ll v,w;
};
vector<edge>g[3*M];
void dijkstra(ll s,ll e){
	for(int i=1;i<=m*3+600;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		ll u=q.top().vv;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto p:g[u]){
			ll v1=p.v,w1=p.w;
			if(dis[v1]>dis[u]+w1){
				dis[v1]=dis[u]+w1;
				q.push({v1,dis[v1]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		ll w;
		scanf("%lld",&w);
		g[i].push_back({i+m,w});
		g[i+m].push_back({i,w});
	}
	ll pos=2*m;
	while(n--){
		ll k;
		scanf("%lld",&k);
		k--;
		ll u,w;
		scanf("%lld%lld",&u,&w);
		g[++pos].push_back({m+u,w});
		g[m+u].push_back({pos,w});
		while(k--){
			scanf("%lld%lld",&u,&w);
			g[pos].push_back({m+u,w});
			g[m+u].push_back({pos,w});
		}
	}
	while(q--){
		ll s,e;
		scanf("%lld%lld",&s,&e);
		if(memo[s][e]){
			printf("%lld\n",memo[s][e]);
			continue;
		}	
		dijkstra(s,e);
		if(s<=3000)
			for(int i=1;i<=3000;i++)
				memo[s][i]=dis[i];
		printf("%lld\n",dis[e]);
	}
	return 0;
}
