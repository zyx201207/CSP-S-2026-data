#include <bits/stdc++.h>
using namespace std;

struct graph{
	vector<pair<int,int>> adj[500];
	int D[505];
	
	void add(int x,int y,int k){
		adj[x].push_back({y,k} );
		adj[y].push_back({x,k} );
	}
	
	int Dijkstra(int s,int e){
		bool vis[500];
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		q.push({s,0});
		int dist[505]{};
		fill(dist,dist+500,INT_MAX);
		dist[s]=0;
		
		while(!q.empty()){
			int cur=q.top().first,len=q.top().second;
			
			if(!vis[cur]) continue;
			vis[cur]=1;
			
			for (auto u:adj[cur]){
				int v=u.first,len=u.second;
				if(!vis[v] && dist[v]>dist[cur]+len){
					dist[v]=dist[cur]+len;
					q.push({v,dist[v]} );
				}
			}
		}
		
		return dist[e];
	}
}G;

int c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i=0;i<m;i++){
		int w;
		cin >> w;
		G.D[i]=w;
	}
	
	for (int i=0;i<n;i++){
		int k;
		cin >> k;
		int a[500005],v;
		for (int j=0;j<k;j++){
			cin >> a[j];
		}
		
		cin >> v;
		for (int j=1;j<k;j++){
			G.add(a[j-1],a[j],v);
		}
	}
	
	for (int i=0;i<q;i++){
		int x,y;
		cin >> x >> y;
		int ans=G.D[x]+G.Dijkstra(x,y)+G.D[y];
		cout << ans << '\n';
	}
	return 0;
}
