#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
#define pll pair<ll,ll>
const ll inf=1e18;
ll o,n,m,d,q,w[500005],k,dis[501050],vis[501050],op,ed;
vector<pll>nex[501005];
priority_queue<pll,vector<pll>,greater<pll> >p;
void dijkstra(){
	for(ll i=1;i<=n+m;i++)
		dis[i]=inf,vis[i]=0;
	p.push({0,op});
	dis[op]=0;
	while(!p.empty()){
		ll u=p.top().second,c=p.top().first;
		p.pop();
		if(vis[u]==1)
			continue;
		vis[u]=1;
		for(auto v:nex[u]){
			if(dis[v.first]>dis[u]+v.second){
				dis[v.first]=dis[u]+v.second;
				p.push({dis[u]+v.second,v.first});
			}
		}	
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>o>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		ll x,c;
		for(ll j=1;j<=k;j++){
			cin>>x>>c;
			nex[x].push_back({i+m,c});
			nex[i+m].push_back({x,c});	
		}
	}
	while(q--){
		cin>>op>>ed;
		dijkstra();
		cout<<w[ed]+w[op]+dis[ed]<<"\n";
	}
	return 0;
}

