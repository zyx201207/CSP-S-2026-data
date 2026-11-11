#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,m,n,d,q,total_node,w[500005];
vector<vector<pair<ll,ll>>> G;
vector<vector<ll>> dist;
vector<pair<ll,ll>> num;
void add_edge(ll u,ll v,ll w){
	G[u].emplace_back(v,w);
}
vector<ll> dij(ll s){
	vector<ll> dis(total_node+1,1LL<<60);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	
	dis[s]=0;
	pq.push({0,s});
	
	while(!pq.empty()){
		ll u=pq.top().second,d=pq.top().first;
		pq.pop();
		
		if(d!=dis[u]) continue;
		
		for(auto edge:G[u]){
			ll v=edge.first,w=edge.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	
	return dis;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	num.emplace_back(0,-1);
	G.emplace_back((vector<pair<ll,ll>>){});
	for(ll i=1;i<=m;++i){
		cin>>w[i];
		G.emplace_back((vector<pair<ll,ll>>){});
		++total_node;
		num.emplace_back(i,0);
	}
	for(ll i=1;i<=n;++i){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;++j){
			ll a,t;
			cin>>a>>t;
			G.emplace_back((vector<pair<ll,ll>>){});
			++total_node;
			num.emplace_back(a,i);
			add_edge(total_node,a,t);
			add_edge(a,total_node,t);
			if(j>1){
				add_edge(total_node,total_node-1,0);
				add_edge(total_node-1,total_node,0);
			}
		}
	}
	
	
	if(c<=11){
		dist.resize(total_node+1);
		for(ll i=1;i<=total_node;++i) dist[i]=dij(i);
		
		while(q--){
			ll x,y;
			cin>>x>>y;
			cout<<(dist[x][y]+w[x]+w[y])<<"\n";
		}
	}
	return 0;
}
