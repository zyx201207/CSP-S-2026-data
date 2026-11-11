#include<bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5 + 10;
int n, q, c, m, d, T[M], sub[N][M];
vector<int> chan[M];
vector<int> go[M][N];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > p[N];
bool pd[M][N];
long long dis[M][N], ans;
void bfs(int a){
	for(auto i : chan[a]){
		while(p[i].size()){
			int u = p[i].top().second;
			p[i].pop();
			pd[u][i] = 0;
			for(auto v : go[u][i]){
				if(dis[v][i] < dis[u][i]) continue;
				if(pd[v][i]) continue;
				pd[v][i] = 1;
				dis[v][i] = dis[u][i];
				p[i].push({dis[v][i], v});
			}
			for(auto j : chan[u]){
				if(dis[u][j] < dis[u][i] + sub[i][u] + sub[j][u]) continue;
				if(pd[u][j]) continue;
				pd[u][j] = 1;
				dis[u][j] = dis[u][i] + sub[i][u] + sub[j][u];
				p[j].push({dis[u][j], u});
			}
		}
	}
	for(int i = 1; i <= n; i++) while(p[i].size()) p[i].pop();
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%d", &T[i]);
	for(int i = 1; i <= n; i++){
		int k, y;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			int x;
			scanf("%d%d", &x, &sub[i][x]);
			chan[x].push_back(i);
			if(j > 1){
				go[x][i].push_back(y);
				go[y][i].push_back(x);
			}
			y = x;
		}
	}
	while(q--){
		memset(pd, 0, sizeof pd);
		memset(dis, 0x3f, sizeof dis);
		int a, b;
		ans = 0;
		scanf("%d%d", &a, &b);
		for(auto i : chan[a]){
			dis[a][i] = sub[i][a];
			p[i].push({dis[a][i], a});
			pd[a][i] = 1;
			bfs(a);
		}
		for(int i = 1; i <= n; i++) ans = max(ans, dis[b][i]);
		printf("%lld\n", ans + T[a] + T[b]);
	}
	return 0;
}
