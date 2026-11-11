#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> p;
ll c,n,m,d,q,u[1005],w1[1005];
ll dis[500005],vis[500005];
int w[505],k[505];
vector<p> g[500005];
void dij(int s){
	for(int i=1;i<=m;i++)
		dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	dis[s]=0;
	priority_queue<p,vector<p>,greater<p>> pq;
	pq.push({dis[s],s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(vis[v]==0 && dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
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
		cin>>k[i]>>u[1]>>w1[1];
		for(int j=2;j<=k[i];j++){
			cin>>u[j]>>w1[j];
			for(int l=1;l<j;l++){
				g[u[l]].push_back({u[j],w1[l]+w1[j]});
				g[u[j]].push_back({u[l],w1[l]+w1[j]});
			}
		}
	}
	while(q--){
		int s,t; cin>>s>>t;
		dij(s);
		cout<<w[s]+w[t]+dis[t]<<"\n";
	}
	return 0;
}
