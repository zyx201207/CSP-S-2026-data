#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

const int N = 6e5 + 5;
const long long inf = 5e15 + 7;

int c, n, m, d, q;
int k[N], val[N];
vector <pi> T[N], Y[N], T1[N];
int head[N], to[N], nxt[N], top;
long long w[N];
struct QUERY {int l, r; long long ans;} quer[N];

inline void add (int u, int v, int W) {
	nxt[++ top] = head[u];
	to[top] = v, w[top] = W;
	head[u] = top;
	return ;
}

priority_queue <pair <long long, int> , vector <pair <long long, int> >, greater <pair <long long, int> > > Q;
long long dis[N];
bool vis[N];
inline void dij (int x) {
	for (int i = 1; i <= n; ++ i) dis[i] = inf, vis[i] = 0;
	Q.push ({0, x});
	dis[x] = 0;
	while (!Q.empty ()) {
		pair <long long, int> x = Q.top ();
		Q.pop ();
		if (vis[x.second]) continue;
		vis[x.second] = 1;
		for (int i = head[x.second]; i; i = nxt[i]) {
			int v = to[i], W = w[i];
			if (dis[v] > x.first + W) {
				dis[v] = x.first + W;
				Q.push ({dis[v], v});
			}
		}
	}
	return ;
}

long long viss[N];

signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i) cin >> val[i];
	for (int i = 1; i <= n; ++ i) {
		cin >> k[i];
		for (int j = 1, x, y; j <= k[i]; ++ j) cin >> x >> y, T[x].push_back ({i, y}), T1[i].push_back ({x, y});
	}
	/*
	第i个站点就是i
	第j条线路是m + j 
	*/
	for (int i = 1; i <= q; ++ i) {
		cin >> quer[i].l >> quer[i].r, quer[i].ans = inf;
		for (auto v : T[quer[i].l]) Y[v.first].push_back ({i, v.second});
	}
	
	for (int i = 1; i <= n; ++ i) {
		for (auto v : T1[i]) {
			viss[v.first] = v.second;
		}
		for (int j = i + 1; j <= n; ++ j) {
			for (auto v : T1[j]) {
				if (viss[v.first]) {
					viss[v.first] += v.second;
					add (i, j, viss[v.first]);
					add (j, i, viss[v.first]);
//					if (viss[v.first] < 0) cout << i << " " << j << "\n";
				}
			}
		}
		for (auto v : T1[i]) viss[v.first] = 0;
	}
	for (int i = 1; i <= n; ++ i) {
		dij (i);
		for (auto v : Y[i]) {
			for (auto v1 : T[quer[v.first].r]) {
				quer[v.first].ans = min (quer[v.first].ans, 1ll * dis[v1.first] + v1.second + val[quer[v.first].l] + val[quer[v.first].r] + v.second);
//				if (dis[v1.first] < 0) cout << v1.first << "\n";
			}
		}
	} 
	for (int i = 1; i <= q; ++ i) cout << quer[i].ans << "\n";
	return 0;
}
/*
注意到d<=20
对于每一个站台建立 d 个节点
它们之间的距离是 t i,j + t i,k
同一条线里面的路径 0 (i -> j) 


根据站点和线路之间的关系建立节点
考虑d<=20这个性质怎么用
500 * n
试试？ 



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
