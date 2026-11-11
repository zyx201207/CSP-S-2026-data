#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;//表示测试点编号、地铁线路数、
	//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	vector<int> t(m+1);
	vector<Edge> e(n);
	vector<vector<pair<int,int>>> g(m+1);
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].w*=2;
		g[e[i].u].push_back({e[i].w,e[i].v});
		g[e[i].v].push_back({e[i].w,e[i].u});
	} 
	for(int i=1;i<=n;i++){
		int wy,x,y;
		cin>>wy>>x>>y;
		vector<int> dist(m+1);
		vector<bool> vis(m+1);
		fill(dist.begin(),dist.end(),0x3f3f3f3f);
		dist[x]=0;
		priority_queue<pair<int,int>> pq;
		pq.push({0,x});
		while(!pq.empty()){
			int u = pq.top().second;
			int d = pq.top().first;
			pq.pop();
			if(d>dist[u]||vis[u])continue;
			vis[u]=1;
			for(auto v:g[u]){
				int b = v.second;
				cout<<'f'<<b<<' ';
				int w = v.first;
				if(d+w<dist[b]){
					dist[b]=d+w;
					pq.push({dist[b],b});
				}
			}
		}
		cout<<dist[y]+t[x]+t[y]<<'\n';
	}
	return 0;
}
