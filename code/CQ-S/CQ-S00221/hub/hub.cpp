#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long
#define fi first
#define se second
#define ppt pair<int, int>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define pb push_back

#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define gch ch = getchar()
void read(int & x) { x = 0; char gch; while(!isdigit(ch)) gch; while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), gch; }
int stk_write[40], top_write;
void write(int x) {
	if(!x) return putchar('0'), void();
	if(x < 0) putchar('-'), x = -x;
	while(x) stk_write[++top_write] = x % 10, x /= 10;
	while(top_write) putchar('0' + stk_write[top_write]), top_write--;
}
const int N = 1e6 + 16;
int Case, n, k, _;

int f_edge[N], cnt_edge;
struct edge { int v, net; } eg[N << 1];
void add(const int u, const int v) { eg[++cnt_edge] = (edge) { v, f_edge[u] }; f_edge[u] = cnt_edge; }
void init_edge() { cnt_edge = 0; FOR(i, 1, n) f_edge[i] = 0; }

// int mac[N][N], sec[N][N];
// void dfs_init(const int u, const int dad, const int rt) {
// 	mac[rt][u] = sec[rt][u] = 0;
// 	for(int i = f_edge[u]; i; i = eg[i].net) {
// 		const int v = eg[i].v; if(v == dad) continue;

// 	}
// }
// void init_mac() {
// 	FOR(rt, 1, n) dfs_init(rt, 0, rt);
// }

int D;
int dep[N], st;
void dfs_dep(const int u, const int dad) {
	dep[u] = dep[dad] + 1;
	if(dep[u] > dep[st]) st = u;
	for(int i = f_edge[u]; i; i = eg[i].net) {
		const int v = eg[i].v; if(v == dad) continue;
		dfs_dep(v, u);
	}
}
void get_D() {
	FOR(i, 1, n) dep[i] = 0;
	dfs_dep(1, 0); int sp = st;
	FOR(i, 1, n) dep[i] = 0;
	dfs_dep(sp, 0);
	D = dep[st];
}

int mac[N], sec[N], tri[N];

int lim;
int g[N];
void dfs_init_g(const int u, const int dad) {
	mac[u] = sec[u] = tri[u] = 0;
	g[u] = 1;
	for(int i = f_edge[u]; i; i = eg[i].net) {
		const int v = eg[i].v; if(v == dad) continue;
		dfs_init_g(v, u);
		if(mac[v] + 1 > mac[u]) tri[u] = sec[u], sec[u] = mac[u], mac[u] = mac[v] + 1;
		else if(mac[v] + 1 > sec[u]) tri[u] = sec[u], sec[u] = mac[v] + 1;
		else if(mac[v] + 1 > tri[u]) tri[u] = mac[v] + 1;

		if(mac[v] + 1 > lim) g[u] += g[v];
	}
}
bool dfs_check(const int u, const int dad, const int able, const int dit, const int dep) {
	if(dit < 0) return false;
	if(g[u] <= able) return true;
	for(int i = f_edge[u]; i; i = eg[i].net) {
		const int v = eg[i].v; if(v == dad) continue;
		int rd = ( mac[u] == (mac[v] + 1) ? sec[u] : mac[u] );
		if(rd + dep <= lim) rd = lim + lim;
		else rd = lim - rd;
		if(dfs_check(v, u, able, min(dit, rd) - 1, dep + 1)) return true;
	}
	return false;
}
// int pg[N], pm[N], ps[N], pt[N];
bool dfs_second(const int u, const int dad) {

	// if(pg[u] >= 0) {
	// 	if(g[u] != pg[u]) cout<<u<<endl, assert(0);
	// 	if(mac[u] != pm[u]) cout<<u<<endl, assert(0);
	// 	if(sec[u] != ps[u]) cout<<u<<endl, assert(0);
	// 	// if(tri[u] != pt[u]) cout<<u<<endl, assert(0);
	// } else {
	// 	pg[u] = g[u];
	// 	pm[u] = mac[u];
	// 	ps[u] = sec[u];
	// 	// pt[u] = tri[u];
	// }

	if(g[u] <= k) return true;
	// cout<<u<<"  "<<dad<<endl;
	for(int i = f_edge[u]; i; i = eg[i].net) {
		const int v = eg[i].v; if(v == dad) continue;
		const int gu = g[u], mu = mac[u], su = sec[u], tu = tri[u];
		const int gv = g[v], mv = mac[v], sv = sec[v], tv = tri[v];

		if(mac[v] + 1 == mac[u]) mac[u] = sec[u], sec[u] = tri[u];
		else if(mac[v] + 1 == sec[u]) sec[u] = tri[u];
		if(mac[v] + 1 > lim) g[u] -= g[v];

		// cout<<u<<" "<<v<<" "<<g[u]<<"  "<<mac[u]<<endl;

		// if(u == 113 and v == 10) {
		// 	cout<<u<<" "<<v<<endl;
		// }
		if(g[u] < k) {

			bool xf = dfs_check(v, u, k - g[u], lim + lim, 1);
			if(xf) return true;

		}

		if(g[v] < k) {

			bool xf = dfs_check(u, v, k - g[v], lim + lim, 1);
			if(xf) return true;
		}

		if(mac[u] + 1 > mac[v]) tri[v] = sec[v], sec[v] = mac[v], mac[v] = mac[u] + 1;
		else if(mac[u] + 1 > sec[v]) tri[v] = sec[v], sec[v] = mac[u] + 1;
		else if(mac[u] + 1 > tri[v]) tri[v] = mac[u] + 1;
		if(mac[u] + 1 > lim) g[v] += g[u];
		bool xf = dfs_second(v, u);
		if(xf) return true;

		g[u] = gu; mac[u] = mu; sec[u] = su; tri[u] = tu;
		g[v] = gv; mac[v] = mv; sec[v] = sv; tri[v] = tv;
	}
	return false;
}
bool check(const int mid) {
	lim = mid;

	// FOR(i, 1, n) pm[i] = pg[i] = ps[i] = pt[i] = -1;
	dfs_init_g(1, 0);
	bool xf = dfs_second(1, 0);

	// dfs_init_g(3, 0);
	// bool xf2 = dfs_second(3, 0);
	// cout<<xf<<" "<<xf2<<endl;

	return xf;
}

// #define lson (k << 1)
// #define rson (k << 1 | 1)
// #define mid ((l + r) >> 1)
// int t[N << 2];
// int gr[N];
// void updata(const int k) { t[k] = min(t[lson], t[rson]); }
// void build(const int k, const int l, const int r) {
// 	if(l == r) return t[k] = gr[l], void();
// 	build(lson, l, mid); build(rson, mid + 1, r); updata(k);
// }
// void chg(const int k, const int l, const int r, const int x, const int y) {
// 	if(l == r) return t[k] = y, void();
// 	if(x <= mid) chg(lson, l, mid, x, y);
// 	else chg(rson, mid + 1, r, x, y);
// 	updata(k);
// }
// int ask(const int k, const int l, const int r, const int x, const int y) {
// 	if(x <= l and r <= y) return t[k];
// 	int ans = n + n;
// 	if(x <= mid) ans = ask(lson, l, mid, x, y);
// 	if(y > mid) ans = min(ans, ask(rson, mid + 1, r, x, y));
// 	return ans;
// }
// #undef lson
// #undef rson
// #undef mid

int gr[N], gl[N];
bool check2(const int lim) {
	int m = n >> 1;
	gr[m + 1] = 0;
	for(int i = m; i >= 1; --i) {
		gr[i] = 1;
		if(m - i + 1 + 1 > lim) gr[i] += gr[i + 1];
	}
	gl[0] = 0;
	FOR(i, 1, m) {
		gl[i] = 1;
		if(i + 1 > lim) gl[i] += gl[i - 1];
	}
	FOR(x, 0, m) if(gl[x] <= k) {
		int tit = lim - 1;
		tit *= 2;
		int py = x + tit + 1;
		// assert( (py - x) / 2 + 1 <= lim );
		py = min(py, m + 1);
		// cout<<x<<" "<<py<<"  "<<gl[x]<<" "<<gr[py]<<" "<<k<<endl;
		if(gl[x] + gr[py] <= k) return true;
	}
	return false;
}
void solve2() {
	int l = 1, r = n, ans = -1;
	// ans = check2(12251);
	while(l <= r) {
		const int mid = (l + r) >> 1;
		if(check2(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans - 1);
}
void solve() {
	_ = scanf("%d%d", &n, &k);
	// cout<<n<<"  "<<k<<endl;
	init_edge();
	FOR(i, 1, n - 1) { int u, v; _ = scanf("%d%d", &u, &v); add(u, v), add(v, u); }
	if(n == k) {
		printf("%d\n", n);
		return ;
	}

	if(n >= 5000 and (Case == 13 or Case == 14)) {
		return solve2(), void();
	}

	// init_mac();
	get_D();
	int l = 0, r = D, ans = -1;
	// cout<<check(9)<<endl;
	while(l <= r) {
		const int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
}
int mian() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T; _ = scanf("%d%d", &Case, &T);
	while(T--) solve();
	return 0;
}/*
0 1
5 2
1 2
2 3
3 4
4 5
*/