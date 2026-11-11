#include <bits/stdc++.h>
using namespace std;

int c , n , m , d , q;
int w[500005];
int k[505];
int t[500005][505];
vector<int> vec[500005];

int graph[505][505];
int dist[505];

inline int dijkstra(int start , int end){
	memset(dist , 0x3f , sizeof(dist));
	priority_queue< pair<int , int> , vector< pair<int , int> > , greater< pair<int , int> > > heap;
	heap.push(make_pair(0 , start));
	dist[start] = 0;
	
	while(!heap.empty()){
		auto pos = heap.top(); heap.pop();
		if(pos.second == end) return pos.first;
		for(int i = 1;i <= 500;i++){
			if(i == pos.second) continue;
			if(graph[pos.second][i] == 0x3f3f3f3f) continue;
			if(dist[i] > dist[pos.second] + graph[pos.second][i]){
				dist[i] = dist[pos.second] + graph[pos.second][i];
				heap.push(make_pair(dist[i] , i));
			}
		}
	}
	return dist[end];
}

int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) {
			int input;
			cin >> input;
			vec[input].push_back(i);
			cin >> t[input][i];
		}
	}
	
	memset(graph , 0x3f , sizeof(graph));
	for(int i = 1;i <= m;i++){
		for(auto j : vec[i]){
			for(int k : vec[i]){
				graph[j][k] = min(graph[j][k] , t[i][j] + t[i][k]);
				graph[k][j] = graph[j][k];
			}
		}
	}
	
	while(q--){
		int start , end; cin >> start >> end;
		
		int ans = 1e9;
		for(int i : vec[start]){
			for(int j : vec[end]){
				ans = min(ans , dijkstra(i , j) + t[start][i] + t[end][j]);
			}
		}
		
		cout << ans + w[start] + w[end] << endl;
	}
	
	return 0;
}
