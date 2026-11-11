#include<bits/stdc++.h>
using namespace std;
int T,c,n,m,d,q,w[20005],dist[505][505],vis[20005];
vector<vector<int>> g(20005);
int bfs(int s,int t) {
	queue<pair<int,int>> q;
	q.push({s,0});
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	while(!q.empty()) {
		auto x=q.front();q.pop();
		int u=x.first;
		if(u==t) return x.second;
		for(auto v:g[u]) {
			if(vis[v]==0) {
				q.push({v,x.second+1});
				vis[v]=1;
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	if(m<=1000) {
		memset(dist,0x3f,sizeof(dist));
		for(int i=1;i<=n;i++) {
			vector<pair<int,int>> e;
			int k;
			cin>>k;
			e.push_back({0,0});
			for(int j=1;j<=k;j++) {
				int v,w;
				cin>>v>>w;
				e.push_back({v,w});
			}
			for(int j=1;j<=k;j++) {
				for(int t=1;t<=k;t++) {
					if(j==t) continue;
					int u=e[j].first,v=e[t].first;
					dist[u][v]=min(dist[u][v],e[j].second+e[t].second);
				}
			}
		}
		for(int k=1;k<=m;k++) {
			for(int i=1;i<=m;i++) {
				for(int j=1;j<=m;j++) {
					if(i==j) continue;
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++) {
			int x,y;
			cin>>x>>y;
			cout<<dist[x][y]+w[x]+w[y]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++) {
		vector<int> e;
		int k;
		cin>>k;
		e.push_back(0);
		for(int j=1;j<=k;j++) {
			int v;
			cin>>v>>T;
			e.push_back(v);
		}
		for(int j=1;j<=k;j++) {
			for(int t=1;t<=k;t++) {
				if(j==t) continue;
				int u=e[j],v=e[t];
				g[u].push_back(v);
			}
		}
	}
	for(int i=1;i<=m;i++) {
		auto kk=unique(g[i].begin(),g[i].end());
		g[i].erase(kk,g[i].end());
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)*2*T+w[x]+w[y]<<endl;
	}
	return 0;
}
