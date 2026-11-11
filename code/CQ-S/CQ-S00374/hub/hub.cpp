#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

// 记得清空 g！！！
int C, T;
vector<int> g[N];

int n, K, col[N], d[N], ans;

bool xd[N];

void coll(int st, int cc) {
	queue<int> q;
	q.push(st); col[st] = cc;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : g[u]) {
			if(!xd[v] || col[v]) continue;
			col[v] = cc; q.push(v);
		}
	}
}

int dis[N]; // i 到每个选的点的最小距离 
void dfs_ds(int u, int fa) {
	for(int v : g[u]) {
		if(v == fa) continue;
		dis[v] = min(dis[v], dis[u]+1);
		dfs_ds(v, u);
	}
}

void dfs_xd(int x, int y) { // 第 x-1 次选的 y 
	if(x == K+1) { // 检验：从一个被选的点出发，染色 
		for(int i=1; i<=n; ++i)
			col[i] = 0;
		coll(y, 1);
		bool flag = 0;
		for(int i=1; i<=K; ++i) {
			if(!col[d[i]]) {
				if(!flag) {
					coll(d[i], 2);
					flag = 1;
				} else return ;
			}
		}
		for(int i=1; i<=n; ++i)
			dis[i] = n*2;
		for(int i=1; i<=K; ++i) {
			dis[d[i]] = 0;
			dfs_ds(d[i], 0);
		}
		int mx = 0;
		for(int i=1; i<=n; ++i) {
			mx = mx>dis[i] ? mx:dis[i];
		}
		ans = min(ans, mx);
		return ;
	}
	for(int i=y+1; i<=n; ++i) {
		xd[i] = 1;
		d[x] = i;
		dfs_xd(x+1, i);
		xd[i] = 0;
	}
}

void sol() {
	scanf("%d%d", &n, &K);
	for(int i=1, u, v; i<n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans = n*2;
	dfs_xd(1, 0);
	printf("%d\n", ans);
	for(int i=1; i<=n; ++i) {
		g[i].clear();
	}
}

int main() {
//	freopen("C:\\Users\\XDFZ\\Desktop\\hub\\hub2.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &C, &T);
	while(T--) sol();
	return 0;
} /*

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

选择恰好 k 个点 在树里面形成 <= 两个连通块
求 不选的点到这些点的距离 的 最大距离 最小。

k=2？枚举选哪两个点，显然任意点对都合法
n<=1000 先算出来每个点到彼此的最短距离，n^2 
好像可以同时预处理出 距离每个点 的最大距离
还要维护次大值，因为最大值有可能是你选的另一个点 
然后枚举点对，n^2，可以快速求最大值。max(u 到所有点的最大值,v 到所有点的最大值) 

 
显然可以枚举一下选哪些点，然后对于选出的点
1. check 几个点在树中形成联通块数
2. 找最大距离 
*/
