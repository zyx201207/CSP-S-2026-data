#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;
ll c,n,m,d,p,u[500005],t[500005],dis[500005],vis[500005],w[500005];
vector<pi>g[500005];
void add(ll u,ll v,ll w){
	g[u].push_back({v,w});
}
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
				pq.push({dis[v],v});
			}
		}
		
	}
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u[j]>>t[j];
			for(int e=1;e<j;e++){
				add(u[j],u[e],t[j]+t[e]);
				add(u[e],u[j],t[j]+t[e]);
			}
		}
		
	}
	while(p--){
		ll u,v;
		cin>>u>>v;
		dij(u);
		cout<<dis[v]+w[u]+w[v]<<'\n';
	}

	
	
	
	return 0;
}
