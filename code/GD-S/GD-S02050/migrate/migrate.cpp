#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;
constexpr int N = 305;
int head[N], nxt[N * N], to[N * N], dnt;
void add_edge(int u, int v)noexcept{
	nxt[++dnt] = head[u];
	head[u] = dnt;
	to[dnt] = v;
//	printf("%d -> %d\n", u, v);
}
//int idx;
//int tid[N << 2];
//void build(int l, int r, int p, int fa)noexcept{
//	if(l == r){
//		tid[p] = l;
//		if(fa)add_edge(fa, l, 0);
//		return;
//	}
//	tid[p] = ++idx;
//	if(fa)add_edge(fa, tid[p], 0);
//	int mid = (l + r) >> 1;
//	build(l, mid, p << 1, tid[p]);
//	build(mid + 1, r, p << 1 | 1, tid[p]);
//}
//void link(int l, int r, int p, int ql, int qr, int u)noexcept{
//	if(ql <= l && r <= qr){
//		add_edge(u, tid[p], 1); 
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if(ql <= mid)link(l, mid, p << 1, ql, qr, u);
//	if(mid < qr)link(mid + 1, r, p << 1 | 1, ql, qr, u);
//}
int n;
ll xd;
int dis[N], g[N];
int q[N], st, ed;
ll a[2000005];
int bfs(int s)noexcept{
	for(int i = 1;i <= n;i++)dis[i] = 1e9, g[i] = 0;
	q[st = ed = 1] = s, dis[s] = 0, g[s] = 1;
	while(st <= ed){
		int u = q[st++];
		for(int d = head[u];d;d = nxt[d]){
			int v = to[d];
			if(dis[v] == dis[u] + 1)g[v] += g[u]; 
			else if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				g[v] = g[u];
				q[++ed] = v;
			}
		}
	}
	int tot = 0;
	for(int i = s + 1;i <= n;i++){
		if(g[i] == 2)tot++;
//		if(s == 1)printf("%d: dis=%d, g=%d\n", i, dis[i], g[i]);
	}
	return tot;
}
void solve2()noexcept{
	scanf("%d%lld", &n, &xd);
	for(int i = 1;i <= n;i++)scanf("%lld", a + i);
	a[n + 1] = 3e18;
	int lim = 1;
	while(lim < n && a[lim + 1] - a[1] <= xd)lim++;
	lim--;
	if(lim <= 1)return puts("0"), void();
	ll ans = 0;
	for(int i = 1;i + lim < n;i++){
		ans += min(n, i + (lim << 1) - 1) - (i + lim);
	}
	printf("%lld\n", lim, ans);
}
void work()noexcept{
	scanf("%d%lld", &n, &xd);
	for(int i = 1;i <= n;i++){
		scanf("%lld", a + i);
	}
	for(int i = 1, r = 1;i <= n;i++){
		while(r < n && a[r + 1] - a[i] <= xd)r++;
//		printf("%d -> (%d, %d]\n", i, i, r);
//		if(i < r)link(1, n, 1, i + 1, r, i);
		for(int j = i + 1;j <= r;j++)add_edge(i, j);
	}
	ll ans = 0;
	for(int i = 1;i < n;i++){
		ans += bfs(i);
	}
	printf("%lld\n", ans);
	for(int i = 1;i <= n;i++)head[i] = 0;
	while(dnt)nxt[dnt] = 0, dnt--;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	int _, _t;scanf("%d%d", &_, &_t);
	if(_ == 11 || _ == 12){
		while(_t--)solve2(); 
	}else{
		while(_t--)work();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4

0 1
6 4
-3 0 1 2 3 4
> 3

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
> 9

11 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
