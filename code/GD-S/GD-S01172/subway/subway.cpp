#include<bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;
ll c,n,m,d,q,w[1000005],k[1000005];
ll dist[1000005],v[1000005];
struct zt_to_xl{
	ll a,t;
}a[1000005];
struct edge{
	ll to,w;
};
vector<edge>e[1000005];
void dij(ll s){
	priority_queue<pll,vector<pll>,greater<pll> > p;
	while(p.size()>0) p.pop();
	for(ll i=1;i<=m;i++) v[i]=0,dist[i]=1e18;
	dist[s]=0;
	p.push({0,s});
	while(p.size()>0){
		ll u=p.top().second;
		p.pop();
		if(v[u]==1) continue;
		v[u]=1;
		for(auto [v,w]:e[u]){
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				p.push({dist[v],v});
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
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[j].a>>a[j].t;
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				e[a[j].a].push_back({a[l].a,a[j].t+a[l].t});
				e[a[l].a].push_back({a[j].a,a[j].t+a[l].t});
			}
		}
	}
	for(ll i=1,x,y;i<=q;i++){
		cin>>x>>y;
		dij(x);
		cout<<dist[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
