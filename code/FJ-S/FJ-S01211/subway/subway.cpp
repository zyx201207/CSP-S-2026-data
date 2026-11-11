#include<bits/stdc++.h>
using namespace std;

struct edge{
	int end;
	int w;
};

struct p{
	int first;
	int second;
	
	bool operator < (const p &other) const{
		return first < other.first;
	}
};

int c, n, m, d, q;
int ex[500005];
int a[500005];
int t[500005];
int r[100005][2];

vector<edge> g[500005];
int dist[500005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qu;

void dijkstra(int src){
	dist[src] = 0;
	qu.push(make_pair(dist[src], src));
	
	while(!qu.empty()){
		
		pair<int, int> minn = qu.top();
		qu.pop();
		
		int min_dist = minn.first;
		int min_index = minn.second;
		
		
		for(int i = 0; i < g[min_index].size(); i++){
			int v = g[min_index][i].end;
			int w = g[min_index][i].w;
			if(min_dist + w < dist[v]){
				dist[v] = min_dist + w;
				qu.push(make_pair(dist[v], v));
			}
		}
		
	}
	
}

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> ex[i];
	}
	
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			//任意一条线路上的两站距离=站厅1到线路站台的距离+站厅2到线路站台的距离
			cin >> a[j] >> t[j];
			
			for(int l = 1; l < j; l++){
				g[a[l]].push_back({a[j], t[j] + t[l]});
				g[a[j]].push_back({a[l], t[j] + t[l]});
			}
		}
	}
	
	for(int i = 1; i <= q; i++){
		cin >> r[i][0] >> r[i][1];
 }
	
	for(int i = 1; i <= q; i++){
		memset(dist, 0x3f3f3f, sizeof(dist));
		dijkstra(r[i][0]);
		cout << dist[r[i][1]] + ex[r[i][0]] + ex[r[i][1]] << endl;
	}
	
	
	
	
	
	return 0;
} 
