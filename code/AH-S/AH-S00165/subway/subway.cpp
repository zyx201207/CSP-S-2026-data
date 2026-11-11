#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
const int N = 510;
const long long MX = 4557430888798830397;
int c, n, m, d, q, w[M], k[N];
long long dis[N][N];
inline int read() {
	int x = 0;
	char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;	
		ch = getchar();
	}
	
	return x;
}
struct edge{
	int to, w; 
};
vector<edge> E[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = read(), n = read(), m = read(), d = read(), q = read();
	
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= m; ++i) {
		w[i] = read();
		
	}
	
	for(int i = 1; i <= n; ++i) {
		dis[i][i] = 0;
		k[i] = read();
		
		for(int j = 1; j <= k[i]; ++j) {
			int a = read(), t = read();
			E[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j < E[i].size(); ++j) {
			for(int kk = j + 1; kk < E[i].size(); ++kk) {
				dis[E[i][j].to][E[i][kk].to] = min(dis[E[i][j].to][E[i][kk].to], 1ll * E[i][j].w + 1ll * E[i][kk].w);
				dis[E[i][kk].to][E[i][j].to] = min(dis[E[i][kk].to][E[i][j].to], 1ll * E[i][j].w + 1ll * E[i][kk].w);
			}
		}
	}
	
	for(int t = 1; t <= n; ++t) {
		for(int x = 1; x <= n; ++x) {
			for(int y = x + 1; y <= n; ++y) {
				if(dis[x][t] < MX && dis[t][y] < MX) {
					dis[x][y] = min(dis[x][y], dis[x][t] + dis[t][y]);
					dis[y][x] = min(dis[y][x], dis[y][t] + dis[t][x]);
				}
			}
		} 
	}
	
	while(q--) {
		int x = read(), y = read();
		long long ans = MX;
		
		for(int i = 0; i < E[x].size(); ++i) {
			for(int j = 0; j < E[y].size(); ++j) {
				ans = min(ans, E[x][i].w + dis[E[x][i].to][E[y][j].to] + E[y][j].w);
			}
		}
		
		printf("%lld\n", 1ll * w[x] + 1ll * w[y] + ans);
	}
}
