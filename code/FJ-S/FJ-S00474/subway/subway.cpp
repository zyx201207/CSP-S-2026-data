#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll val[500005];
vector<pair<int,ll> >adj[500505];
ll dis[500505];
bool vis[500505];
struct node{
	int id;
	ll disid;
	bool operator < (const node t) const {
		return t.disid<disid;
	}
};
priority_queue<node>pq;
ll dijkstra(int s,int t){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	while(pq.size()) pq.pop();
	dis[s]=0;
	pq.push({s,0});
	while(pq.size()){
		node p=pq.top();
		pq.pop();
		int u=p.id;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:adj[u]){
			int v=e.first;
			ll w=e.second;
			if(dis[v]>p.disid+w){
				dis[v]=p.disid+w;
				pq.push({v,dis[v]});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++) cin>>val[j];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			adj[m+i].push_back({a,t});
			adj[a].push_back({m+i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<val[x]+val[y]+dijkstra(x,y)<<"\n";
	}
	return 0;
}
