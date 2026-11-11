#include<bits/stdc++.h>
#define LL long long int 
#define pii pair<LL,int>
using namespace std;
const int M=5e5+10,N=5e6+10;
int c,n,m,d,q,idx;
LL a[M],dis[N];
vector<pii> g[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
LL dijkstra(int st,int ed){
	memset(dis,0x3f,sizeof dis);
	dis[st]=0ll;
	pq.push({0ll,st});
	while(pq.size()){
		int u=pq.top().second;
		LL dist=pq.top().first;
		pq.pop();
		for(auto t:g[u]){
			int v=t.second;
			LL w=t.first;
			if(dist+w<dis[v]){
				dis[v]=dist+w;
				pq.push({dis[v],v});
			}
		}
	}
	return dis[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&c);
	if(7<=c&&c<=11){
		scanf("%d%d%d%d",&n,&m,&d,&q);
		for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			int x,vs,ve;
			LL ws,we;
			scanf("%d",&x);
			if(x==1) continue;
			scanf("%d%lld%d%lld",&vs,&ws,&ve,&we);
			g[vs].push_back({ws+we,ve});
			g[ve].push_back({ws+we,vs});
		}
		for(int i=1;i<=q;i++){
			int st,ed;
			scanf("%d%d",&st,&ed);
			LL ansd=dijkstra(st,ed);
			printf("%lld\n",ansd+a[st]+a[ed]);
		}
	} 
	else{
		scanf("%d%d%d%d",&n,&m,&d,&q);
		idx=m;
		for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			int x,v;
			LL w;
			scanf("%d",&x);
			for(int j=1;j<=x;j++){
				scanf("%d%lld",&v,&w);
				g[v].push_back({w,++idx});
				g[idx].push_back({w,v});
				if(j>1){
					g[idx].push_back({0,idx-1});
					g[idx-1].push_back({0,idx});
				}
			}
		}
		for(int i=1;i<=q;i++){
			int st,ed;
			scanf("%d%d",&st,&ed);
			LL ansd=dijkstra(st,ed);
			printf("%lld\n",ansd+a[st]+a[ed]);
		}
	}
	return 0;
}
