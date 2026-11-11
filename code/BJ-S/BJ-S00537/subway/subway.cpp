#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f, MAXN = 600, MAXM = 5000 + 500, MAXQ = 1e5 + 100;

int c, n, m, d, q;    // 分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。
int w[MAXM];          // 每个地铁站的地铁口走到站厅需要的时间。
int k[MAXN];          // 第 i 条线路经过的地铁站数
int a[MAXN][MAXM];    // a_{i,j} 表示第 i 条线路经过的第 j 个地铁站
int t[MAXN][MAXM];    // t_{i,j} 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
int x[MAXQ], y[MAXQ]; // 第 r 个出行计划的起点和终点所在的地铁站编号。
int g[MAXN][MAXN]

int dis[MAXM][MAXM];
bool vis[MAXM];

pair<int, int> pq[MAXM];
int head, rear;

void dj(int s, int t) {
	
}

signed main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("subway.in", "r", stdin);
	// freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1; i <= q; i++)
		cin >> x[i] >> y[i];
	
	for(int num = 1; num <= n; num++)
		for(int i = 1; i <= k[num]; i++)
			for(int j = i + 1; j <= k[num]; j++)
				g[a[num][i]][a[num][j]] = t[num][a[num][i]] + t[num][a[num][j]]};
	
	for(int u = 1; u <= m; u++)
		for(int v = 1; v <= m; v++)
			for(int z = v; z <= m; z++) {
				dis[]dis[u][v] = min(dis[u][v] + dis[u][z] + dis[z][u])
			}
	
	return 0;
}
