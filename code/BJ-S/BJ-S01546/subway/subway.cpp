#include<bits/stdc++.h>
#define ll long long
using namespace std;
int w[500005],k[505],dis[500505],vis[500505];
vector<pair<ll,ll> >g[500505];
ll dijkstra(ll x,ll y){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	q.push({0,x});
	while(q.size()){
		ll u=q.top().second;
		q.pop();
		if(vis[u]==1){
			continue;
		}
		vis[u]=1;
		for(auto k:g[u]){
			ll v=k.first,w=k.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll x,y;
			cin>>x>>y;
			g[x].push_back({i+500005,y});
			g[i+500005].push_back({x,y});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}