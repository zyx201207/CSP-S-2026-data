#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;
ll c,t,n,k,dis[500005],vis[500005],maxx=0,minn=0x3f3f3f3f;
vector<pi>g[500005];
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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			g[u].push_back({v,1});
			g[v].push_back({u,1});
		}
		
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				if(dis[j]!=0x3f3f3f3f) maxx=max(maxx,dis[j]);
			}
			minn=min(minn,maxx);
		}
		cout<<minn<<'\n';
	}

	
	
	
	return 0;
}
