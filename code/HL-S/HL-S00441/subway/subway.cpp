#include <bits/stdc++.h>//dijkstra,1~8,time:O(qMlogM),M=sigma k+nd;space:O(nmd);30pts
using namespace std;//only walking time
#define int long long//see ancestor!!!
int c,n,m,d,q,x,y,mx;
signed main(){
	freopen("subway.in","r",stdin);//don't forget!!!
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+10),k(n+10),dis(m*(n+1)+10),vis(m*(n+1)+10);
	vector<vector<int>> a(n+10),t(n+10);
	vector<vector<pair<int,int> > > g(m*(n+1)+10);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);//1-based
		t[i].push_back(0);
		for(int j=1,aa,tt;j<=k[i];j++){
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	for(int i=1;i<=n;i++)//build the graph
		for(int j=1;j<=k[i];j++){
			g[a[i][j]].push_back({m*i+a[i][j],t[i][j]});//error is here
			g[m*i+a[i][j]].push_back({a[i][j],t[i][j]});//edges between stations and lines
			if(j!=k[i]){
				g[m*i+a[i][j]].push_back({m*i+a[i][j+1],0});//edges on subway lines
				g[m*i+a[i][j+1]].push_back({m*i+a[i][j],0});
			}
		}
	auto dijkstra=[&](){//get the shortest walking time
		priority_queue<pair<int,int> > q;
		q.push({0,x});
		for(int i=1;i<=m*(n+1);i++){
			dis[i]=0x3f3f3f3f3f3f3f3f;
			vis[i]=0;
		}
		dis[x]=0;
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto it:g[u]){
				int v=it.first,w=it.second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					q.push({-dis[v],v});
				}
			}
		}
		return ;
	};
	while(q--){
		cin>>x>>y;
		dijkstra();
		cout<<w[x]+w[y]+dis[y]<<'\n';
	}
	return 0;
}/*example1
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/