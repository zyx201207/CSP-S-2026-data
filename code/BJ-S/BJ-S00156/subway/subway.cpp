#include<bits/stdc++.h>

using namespace std;

int a[507];
struct edge{
	int v,w;
};
vector<edge> g[1007];
int dis[1007][1007];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	if(7<=c&&c<=11){
		for(int i=1;i<=m;++i){
			cin >> a[i];
		}
		for(int i=1;i<=n;++i){
			int k;
			cin>> k;
			if(k==1){
				int u,v;
				cin >> u >> v;
				continue;
			}
			else{
				int u,v,w1,w2;
				cin >> u >> w1 >> v >> w2;
				g[u].push_back({v,w1+w2});
				g[v].push_back({u,w1+w2});
			}	
		}
		for(int j=1;j<=m;j++){
			int st = j;
			for(int i=1;i<=m;++i){
				dis[st][i] = INT_MAX;
			}
			priority_queue<pair<int,int> >q;
			q.push({0,st});
			dis[st][st] = 0;
			while(!q.empty()){
				pair<int,int> now = q.top();
				q.pop();
				for(int i=0;i<g[now.second].size();++i){
					int v = g[now.second][i].v;
					int w = g[now.second][i].w;
					if(dis[st][v] > dis[st][now.second]+w){
						dis[st][v] = dis[st][now.second]+w;
						q.push({dis[st][v],v});
					}
				}
			}
		}
		while(q--){
			int u,v;
			cin >>u >> v;
			cout << dis[u][v]+a[u]+a[v] << '\n';
		}
	}
}
