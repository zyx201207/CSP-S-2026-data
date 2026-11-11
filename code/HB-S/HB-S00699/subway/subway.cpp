#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

const int N = 505;
const int M = 5e5 + 10;
const int D = 21;
const int INF = 0x3f3f3f3f;

typedef std::pair<int, int> pii;

int c, n, m, d, q;  // n: path num, m: station num 
int w[M];  // door -> hall
int k[N];  // path cross station num
int a[M];  // path i cross station M
int s_p_len[N];
pii s_p[N][D];  // station s has p path
int p_time[N][N];

/*
bool vis[N];
int dis[N];
int dijkstra(int s, int end){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	while(true){
		int u, mn=INF;
		for(int i=1; i<=n; i++){
			if(!vis[i] && dis[i] < mn){
				mn = dis[i];
				u = i;
			}
		}
		if(mn == INF) break;
		vis[u] = 1;
		for(int v=1; v<=n; v++){
			if(p_time[u][v] == INF) continue;
			if(dis[u] + p_time[u][v] <= dis[v]){
				dis[v] = dis[u] + p_time[u][v];
			}
		}
	}
	return dis[end];
}*/
int dis[N];
std::vector<pii> edge[N];
int dijkstra(int s, int end){
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
	q.push({0, s});
	while(q.size()){
		int d = q.top().first, u = q.top().second;
		q.pop();
		if(d != dis[u]) continue;
		for(pii data: edge[u]){
			int v = data.first, w = data.second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
	return dis[end];
}

int main(){
	std::freopen("subway.in", "r", stdin);
	std::freopen("subway.out", "w", stdout);
	std::cin >> c >> n >> m >> d >> q;
	memset(p_time, 0x3f, sizeof(p_time));
	for(int i=1; i<=m; i++) std::cin>>w[i];
	for(int i=1; i<=n; i++){
		std::cin >> k[i];
		p_time[i][i] = 0;
		for(int j=1; j<=k[i]; j++){
			int x, t;
			std::cin >> x >> t;
			s_p[x][s_p_len[x]++] = {i, t};
			for(int kkk=0; kkk < s_p_len[x]; kkk++){//for(pii data: s_p[x]){
				pii data = s_p[x][kkk];
				int p1 = data.first, t1 = data.second;
				if(p1 == i) continue;
				int min_time = std::min(std::min(p_time[i][p1], p_time[p1][i]), t + t1);
				p_time[i][p1] = p_time[p1][i] = min_time;
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(p_time[i][j] != INF){
				edge[i].push_back({j, p_time[i][j]});
			}
		}
	}

	for(int i=1; i<=q; i++){
		int x, y;
		std::cin >> x >> y;
		int res = INF;
		for(int kkk=0; kkk < s_p_len[x]; kkk++){
			pii data = s_p[x][kkk];
			int u = data.first, t1=data.second;
			for(int kkk1=0; kkk1 < s_p_len[y]; kkk1++){
				pii data1 = s_p[y][kkk1];
				int v = data1.first, t2=data1.second;
				res = std::min(res, t1 + t2 + dijkstra(u, v));
			}
		}
		std::cout << w[x] + w[y] + res << std::endl;
	}
	/*for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			std::cout << p_time[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
	return 0;
}