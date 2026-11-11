#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;
ll c,t,d,n,a[2000005],dis[2000005],vis[2000005];
vector<pi>g[2000005];
void add(ll u,ll v,ll w){
	g[u].push_back({v,w});
}
unordered_map<ll,ll> mp;
void dij(ll start){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[start]=0;
	priority_queue<pi,vector<pi>,greater<pi>>pq;
	pq.push({dis[start],start});
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			ll v=g[u][i].first;
			ll w=g[u][i].second;
			if(!vis[v]&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				mp[dis[v]]++;
				pq.push({dis[v],v});
			}
		}
		
	}
	
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
					g[j].push_back({i,a[i]-a[j]});
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				dij(i);
				if(mp[dis[j]]==2)ans++;
			}
		}
		cout<<ans<<'\n';
		
		
	}

	
	
	
	return 0;
}
