#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+100,M=1e18;
struct edge{
	int v,w;
};
int c,n,m,d,q,w[N],k[N],a[N],t[N],dist[N];
bool vis[N];
vector<edge>e[N];
void dij(int st){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	for(int i=1;i<=m+n;i++){
		vis[i]=false;
		dist[i]=M;
	}
	dist[st]=0;
	q.push({0,st});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[j],&t[j]);
			e[a[j]].push_back({m+i,t[j]});
			e[m+i].push_back({a[j],t[j]});
		}
	}
	while(q--){
		int st,ed;
		scanf("%lld%lld",&st,&ed);
		dij(st);
		printf("%lld\n",dist[ed]+w[st]+w[ed]);
	}
	return 0;
} 
