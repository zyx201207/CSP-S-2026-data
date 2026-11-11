#include <cstdio>
#include <queue> 
#include <vector>
#define N 1005
using namespace std;
int i, j, k, n, m, l, r, ans, c, T, u ,v;
int xuan[N];
int bfs(int x, vector<vector<int>> g){
	queue <int> q;
	vector <int> dis;
	int ans = 1;
	q.push(x), dis[x] = 1;
	while(!q.empty()){
		int u = q.front();
		for(auto v : g[u]){
			if(dis[v]) continue;
			dis[v] = dis[u] + 1;
			ans = max(ans, dis[v]);
			if(xuan[v]) return dis[v] - 1;
		}
	}
	return -1;
} 
void dfs(int k, int x, vector<vector<int>> g){
	if(x > m) return;
	if(k > m && x == m){
		int cur = 0;
		for(i=1; i<=n; i++){
			if(!xuan[i]) cur = max(cur, bfs(i, g));
		}
		ans = min(ans, cur);
		return;
	}
	xuan[k] = 1;
	dfs(k+1, x+1, g);
	xuan[k] = 0;
	dfs(k+1, x, g);
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--){
		vector<vector<int>> g;
		g.resize(m+5);
		scanf("%d%d", &n, &m);
		for(i=1; i<n; i++){
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0, g);
		printf("%d\n", ans);
	}
	return 0;
}

