#include<bits/stdc++.h>
using namespace std;

int w[500005] = {};
int n, m, d, q1, t = 0;					//n:线路数量  m:地铁站数量  d:每个地铁站最多被d条线路经过 q:出行计划数量 
long long dist[5005][5005] = {};		//dist[i][j] -> 站台i到达站台j的最短路径 
bool vis[500005] = {};
vector<vector<int> >adj(50005);
queue<int>q;			//f:站台编号 s:从哪一条线路过来 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> n >> n >> m >> d >> q1;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;						//k:这条路上的站台数量 
		int x[505] = {};			//x[i]:该线路上的第i个站台 
		int t1[505] = {};			//t[i]:该线路上i的站台到站厅的时间 
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> x[j] >> t1[j];
		}
		t = t1[1];
		for(int j = 1; j <= k - 1; j++){
			adj[x[j]].push_back(x[j + 1]);
			adj[x[j + 1]].push_back(x[j]);
		}
	}
	
	while(q1--){
		int x, y;
		cin >> x >>y;
		
		q.push(x);
		dist[x][x] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			for(int v:adj[u]){
				if(vis[v])continue;
				vis[v] = true;
				dist[x][v] = dist[x][u] + 1;
				q.push(v);
			}
		}
		cout << w[x] + w[y] + dist[x][y] * t << endl;
	}
	
	return 0;
}
