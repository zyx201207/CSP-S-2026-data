#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,tot;
long long dis[2000006];
vector<pair<int,long long> > g[2000006];
bool vis[2000006];
void dij(int s){
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
	for(int i=0;i<=tot;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[s]=0,pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.first;
			long long w=e.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		long long w;
		cin>>w;
		g[i].push_back({i+m,w});
		g[i+m].push_back({i,w});
	}
	tot=m*2;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		tot++;
		for(int j=1;j<=k;j++){
			int a;
			long long t;
			cin>>a>>t;
			g[a+m].push_back({tot,t});
			g[tot].push_back({a+m,t});
		}
	}
//	cout<<tot<<'\n';
	while(q--){
		int s,t;
		cin>>s>>t;
		dij(s);
		cout<<dis[t]<<'\n';
	}
	return 0;
}
