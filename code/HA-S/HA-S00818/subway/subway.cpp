#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k;
long long x,y,u,v,h[500005];
long long dist[500005];
vector<vector<pair<long long,long long> > > g(500005);
void daji(){
	memset(dist,0x3f,sizeof dist);
	priority_queue<pair<long long,long long> > q;
	dist[u]=0;
	q.push({dist[u],u});
	while(q.size()){
		long long x=q.top().second;
		q.pop();
		for(int i=0;i<h[x];i++){
			long long b=g[x][i].second;
			long long a=g[x][i].first;
			if(dist[x]+b<dist[a]){
				dist[a]=dist[x]+b;
				q.push({(-dist[a]),a});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>x>>y;
			h[m+i]++;
			g[m+i].push_back({x,y});
			h[x]++;
			g[x].push_back({m+i,y});
		}
	}
	while(q--){
		cin>>u>>v;
		daji();
		cout<<dist[v]+w[u]+w[v]<<endl;
	}
	return 0;
}
