#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, m, c, t, d;
int dist[N];
int x, y;
struct node{
	int to, dis, num;
}; 
vector<node> g[N*50];
int ans = INT_MAX;
void djikstra(int x){
	bool vis[N];
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q; 
	q.push({x, 0}); 
	int line = 0; 
	while(!q.empty()){
		int u = q.top().first;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto e:g[u]){
			int v = e.to, w = 0, line_num = e.num;
			if(line != line_num){
				w = g[v][u].dis + g[u][v].dis;
				line = line_num;
			}
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u]+w;
				q.push({v, dist[v]});
			}
		}
 	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c;
		int k = 0;
		cin>>n>>m>>d>>t;
		int hall_time[m];
		for(int i=1;i<=m;i++) cin>>hall_time[i];
		for(int i=1;i<=n;i++){ //n个线路 i
			cin>>k;
			int platforms[k], platform_time[m];
			for(int j= 1; j<=k;j++) cin>>platforms[j]>>platform_time[platforms[j]]; //输入站台和时间 
			for(int j=2;j<=k;j++){ 
					int u = platforms[j-1];
					int v = platforms[j];
					g[u].push_back({v, platform_time[u], i});
					g[v].push_back({u, platform_time[v], i});
			}
		}
		for(int i=1;i<=t;i++){
			cin>>x>>y;
			djikstra(x);
			cout<<dist[y]+hall_time[y]+hall_time[x]<<"\n";
		}
}
