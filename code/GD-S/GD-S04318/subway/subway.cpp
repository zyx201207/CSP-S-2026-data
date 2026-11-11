#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=5e4+5;
int w[M],o[505][M],u[505][M],l[505];
int dis[M],vis[M];
unordered_map<int,int>mp;
vector<pair<int,int> >G[M];
int dijkstra(int s,int t) {
	memset(dis,0x3f3f3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	vis[s]=1;
	priority_queue<pair<int,int> >q;
	q.push({0,s});
	while(!q.empty()) {
		auto t=q.top().second;
		vis[t]=1;
		q.pop();
		for(auto v:G[t]) {
			if(vis[v.first]) continue;
			if(dis[v.first]>dis[t]+v.second) {
				dis[v.first]=dis[t]+v.second;
				q.push({-dis[v.first],v.first});
			}
		}
	}
	return dis[t];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>l[i];
		for(int j=1; j<=l[i]; j++) {
			cin>>u[i][j]>>o[i][j];
			mp[u[i][j]]++;
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=2; j<=l[i]; j++) {
			if(mp[u[i][j]]==1)
				G[u[i][j-1]].push_back({u[i][j],0});
			else
				for(int k=i+1; k<=n; k++)
					for(int t=1; t<=l[k]; t++)
						if(u[k][t]==u[i][j]) {
							G[u[i][j-1]].push_back({u[i][j],o[i][j]+o[k][t]});
							break;
						}
		}
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
