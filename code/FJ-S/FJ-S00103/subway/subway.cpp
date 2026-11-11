#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll dist[600010],c,n,m,d,q,w[500010],nn;
vector<pii>g[600010];
bool vis[600010];
void dijkstra(int s){
	for(int i=1;i<=nn;i++) dist[i]=1e18;
	fill(vis+1,vis+nn+1,0);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	dist[s]=0;
	while(!q.empty()){
		pii tp=q.top();
		ll u=tp.second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto tp:g[u]){
			ll v=tp.first,w=tp.second;
			if(vis[v]) continue;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			g[i+m].push_back({v,w});
			g[v].push_back({i+m,w});
		}
	}
	for(int i=1;i<=m;i++){
		g[i].push_back({n+m+i,w[i]});
		g[n+m+i].push_back({i,w[i]});
	}
	nn=2*m+n;
	//for(int i=1;i<=2*m+n;i++){
	//	for(int j=0;j<g[i].size();j++){
	//		cout<<i<<": "<<g[i][j].first<<' '<<g[i][j].second<<endl;
	//	}
	//}
	//for(int i=1;i<=m;i++){
	//	dijkstra(n+m+i);
	//}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(n+m+x);
		cout<<dist[n+m+y]<<endl;
	}
}
