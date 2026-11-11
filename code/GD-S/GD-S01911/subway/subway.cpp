#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5, inf = 1e18;
int c, n, m, d, q, w[maxn], tot, head[maxn << 1], dis[maxn], ans[maxn];
struct nd{
	int to, nxt, w;
}e[maxn << 1];
struct Q{
	int x, y, id;
}a[maxn];
bool cmp(Q x, Q y){
	return x.x < y.x;
}
struct dij{
	int dis, u;
	bool operator < (const dij &tmp) const{
		return tmp.dis < dis;
	}
};
void add(int u, int v, int w){
	e[++tot] = {v, head[u], w};
	head[u] = tot;
}
void Dij(int x){
	for (int i = 1; i <= n; i++) dis[i] = inf; dis[x] = 0;
	priority_queue <dij> q; q.push({0, x});
	while(!q.empty()){
		int u = q.top().u, d = q.top().dis;
		q.pop(); if (d > dis[u]) continue;
		for (int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to;
			if (dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w; q.push({dis[v], v});
			}
		}
	}
}
main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, x, t; j <= k; j++) cin >> x >> t, add(x, i + m, t), add(i + m, x, t);
	}n += m;
	for (int i = 1; i <= q; i++) {
		cin >> a[i].x >> a[i].y, a[i].id = i; if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
	}sort(a + 1, a + q + 1, cmp); a[0].x = -1;
	for (int i = 1; i <= q; i++) {if (a[i].x ^ a[i - 1].x) Dij(a[i].x); ans[a[i].id] = dis[a[i].y] + w[a[i].x] + w[a[i].y];}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
