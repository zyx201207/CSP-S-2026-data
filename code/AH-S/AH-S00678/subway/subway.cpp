#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pli=pair<ll,int>;
struct edge{
	int v; ll t;
};
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<vector<edge>> g(2*m+n+1);
	vector<vector<ll>> dist(n+1,vector<ll>(2*m+n+1,1ll<<62));
	for(int i=1;i<=m;i++){
		ll t; cin>>t;
		g[i+n].push_back({i+n+m,t});
		g[i+n+m].push_back({i+n,t});
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		while(k--){
			int a; ll t; cin>>a>>t;
			g[a+n+m].push_back({i,t});
			g[i].push_back({a+n+m,t});
		}
	}
	if(c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			queue<pli> pq;
			vector<int> vis(2*m+n+1,false);
			pq.push({0,i}),dist[i][i]=0;
			while(!pq.empty()){
				pli now=pq.front(); pq.pop();
				int u=now.second;
				if(vis[u]==true) continue;
				vis[u]=true;
				for(edge e:g[u]){
					int v=e.v; ll d=e.t;
					if(dist[i][u]+d<dist[i][v]){
						dist[i][v]=dist[i][u]+d;
						pq.push(make_pair(dist[i][v],v));
					}
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			priority_queue<pli,vector<pli>,greater<pli>> pq;
			vector<int> vis(2*m+n+1,false);
			pq.push({0,i}),dist[i][i]=0;
			while(!pq.empty()){
				pli now=pq.top(); pq.pop();
				int u=now.second;
				if(vis[u]==true) continue;
				vis[u]=true;
				for(edge e:g[u]){
					int v=e.v; ll d=e.t;
					if(dist[i][u]+d<dist[i][v]){
						dist[i][v]=dist[i][u]+d;
						pq.push(make_pair(dist[i][v],v));
					}
				}
			}
		}
	}
	while(q--){
		int x,y; ll ans=(1ll<<62); cin>>x>>y;
		for(int i=1;i<=n;i++){
			ans=min(ans,dist[i][x+n]+dist[i][y+n]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
