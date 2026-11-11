#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long

typedef pair<signed, signed> PII;
signed read(){
	signed x = 0;
	char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while('0' <= c && c <= '9')x = x * 10ll + (c - '0'), c = getchar();
	return x;
//	signed x; scanf("%d", &x); return x; 
}

const int N = 530;
const int M = 5e5 + 100;
const int INF = 1e17 + 100;

int n, m, q;

int w[M];
vector<PII> e[M];
int dis[N][N];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int cid; cid = read(); n = read(); m = read(); cid = read(); q = read();
	
	for(int i = 1; i <= m; i ++)w[i] = read();
	for(int i = 1; i <= n; i ++){
		int k = read();
		for(int j = 1; j <= k; j ++){int a = read(), b = read(); e[a].push_back({i, b}); }
		for(int j = 1; j <= n; j ++)
			if(i != j)dis[i][j] = INF;
	}
	
	for(int p = 1; p <= m; p ++){
		for(int i = 0; i < e[p].size(); i ++){
			int u = e[p][i].first, x = e[p][i].second;
			for(int j = 0; j < e[p].size(); j ++){
				int v = e[p][j].first, y = e[p][j].second;
				dis[u][v] = min(x + y, dis[u][v]);
			}
		}
	}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
	
	for(int z = 1; z <= q; z ++){
		int x = read(), y = read(), ans = INF;
		for(int i = 0; i < e[x].size(); i ++)
			for(int j = 0; j < e[y].size(); j ++)
				ans = min(e[x][i].second  + e[y][j].second + dis[e[x][i].first][e[y][j].first], ans);
		ans += w[x] + w[y];
		printf("%lld\n", ans);
	}
	
	return 0;
}
