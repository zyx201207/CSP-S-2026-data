#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll>pi;
const ll N=5e5+1000;
ll c,n,m,d,q;
ll a[N];
ll dis[N];
ll vis[N];
vector<pi>g[N];
ll cnt=1;
void dij(ll s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pi,vector<pi>,greater<pi>>pq;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			ll v=g[u][i].first;
			ll w=g[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	cnt=n+1;
	for(int i=1;i<=n;i++){
		ll k;ll u,w;
		cin>>k;
		while(k--){
			cin>>u>>w;
			g[i+m].push_back({u,w});
			g[u].push_back({i+m,w});
		}
	}
	while(q--){
		ll s,t;cin>>s>>t;
		dij(s);
		cout<<dis[t]+a[s]+a[t]<<"\n";
	}
	return 0;
}
