#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
// #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
using ll = long long;

char buf[1 << 20], *p1 = buf, *p2 = buf;
char gc(void) {
	if(p1 == p2) p1 = buf, p2 = buf + fread(buf, 1, 1 << 20, stdin);
	return *p1++;
}
int in(void) {
	int x = 0, f = 1; char c = gc();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = gc();
	}
	while(isdigit(c)) x = x * 10 + c - '0', c = gc();
	return x * f;
}
ll inl(void) {
	ll x = 0, f = 1; char c = gc();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = gc();
	}
	while(isdigit(c)) x = x * 10 + c - '0', c = gc();
	return x * f;
}

using namespace std;
// auto st = chrono::system_clock::now();
const int kN = 1000050;
inline void chkmax(int &a, int b) { a = max(a, b); }
int n, k, mid; vector<int> g[kN];
// int tot, rt, rtv, siz[kN];
// void getsize(int u, int fa) { ++tot; for(auto &v : g[u]) if(v != fa) getsize(v, u); }
// void findrt(int u, int fa, int ban) {
// 	siz[u] = 1; int k = 0;
// 	for(auto &v : g[u]) if(v != fa && v != ban) {
// 		findrt(v, u, ban), siz[u] += siz[v];
// 		chkmax(k, siz[v]);
// 	}
// 	chkmax(k, tot - siz[u]);
// 	if(k < rtv) rt = u, rtv = k;
// }
int cnt;
int dfs(int u, int fa, int ban) {
	int mxd = 0;
	for(auto &v : g[u]) if(v != fa && v != ban) chkmax(mxd, dfs(v, u, ban) + 1);
	if(mxd >= mid || fa == 0) ++cnt;
	return mxd;	
}
int dep[kN], ff[kN], p, pv;
void dfs0(int u, int fa, int ban = -1) {
	dep[u] = dep[fa] + 1, ff[u] = fa;
	if(dep[u] > pv) p = u, pv = dep[u];
	for(auto &v : g[u]) if(v != fa && v != ban) dfs0(v, u, ban);
}
bool check(int u, int v) {
	// debug("chk(%d %d)\n", u, v);
	int tot1 = 1e9, tot2 = 1e9;
	pv = -1e9, dfs0(u, v); int rt = p;
	pv = -1e9, dfs0(p, 0, v);
	vector<int> path;
	while(p != rt) path.push_back(p), p = ff[p]; path.push_back(p);
	cnt = 0, dfs(path[path.size() / 2], 0, v), tot1 = min(tot1, cnt);
	if(path.size() > 1) cnt = 0, dfs(path[path.size() / 2 - 1], 0, v), tot1 = min(tot1, cnt); 
	pv = -1e9, dfs0(v, u); rt = p;
	pv = -1e9, dfs0(p, 0, u);
	path.clear();
	while(p != rt) path.push_back(p), p = ff[p]; path.push_back(p);
	cnt = 0, dfs(path[path.size() / 2], 0, u), tot2 = min(tot2, cnt);
	if(path.size() > 1) cnt = 0, dfs(path[path.size() / 2 - 1], 0, u), tot2 = min(tot2, cnt); 
	// debug("OK!\n");
	// cnt = 0;
	// debug("u = %d, v = %d\n", u, v);
	// tot = 0, getsize(u, v), rtv = 1e9;
	// debug("rt=%d\n",rt);
	// findrt(u, v, v), dfs(rt, 0, v);
	// tot = 0, getsize(v, u), rtv = 1e9;
	// debug("rt=%d\n",rt);
	// findrt(v, u, u), dfs(rt, 0, u);
	return tot1 + tot2 <= k;
} int tot;
void solve(void) {
	n = in(), k = in(); tot += n;
	_rep(i,1,n) g[i].clear();
	_rep(i,2,n) {
		int u = in(), v = in();
		g[u].push_back(v), g[v].push_back(u);
	}
	if(k == n) {
		puts("0");
		return;
	}
	dfs0(1, 0);
	int d0 = max_element(dep + 1, dep + 1 + n) - dep;
	dfs0(d0, 0);
	int w0 = max_element(dep + 1, dep + 1 + n) - dep;
	vector<int> path;
	while(w0 != d0) path.push_back(w0), w0 = ff[w0];
	path.push_back(d0);
	int m = path.size();
	// debug("m = %d\n", m);
	// for(auto &u : path) debug("%d ", u); debug("\n");
	int L = 1, R = m / 2, ans = -1;
	while(L <= R) {
		mid = L + R >> 1;
		// debug("mid = %d\n", mid);
		// if(k == 2) {
		// 	int x = 
		// }
		if(n <= 4000) {
			bool flg = 0;
			_rep(u,1,n) for(auto &v : g[u]) if(v < u && check(u, v)) {
				flg = 1; goto out;
			}
			out:
			if(flg) ans = mid, R = mid - 1; else L = mid + 1;
			continue;
		}
		bool flg = 0;
		_rep(x,max(0,m/2-2),min(m-1,m/2+2)){
			int v = path[x];
			for(auto &w : g[v]) if(check(v, w)) {
				flg = 1; break;
			}
			if(flg) break;
		}
        // int w = path[m / 2];
        // // debug("siz = %d\n", g[w].size());
        // for(auto &v : g[w]) if(check(v, w)) {
        //     flg = 1; break;
        // }
		// if(check(path[m / 2], path[m / 2 - 1])) flg = 1;
		// if(check(path[m / 2], path[m / 2 + 1])) flg = 1;
		// _rep(u,1,n) for(auto &v : g[u]) if(v < u && check(u, v)) {
		// 	flg = 1; break;
		// }
		if(flg) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	printf("%d\n", ans);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	in(); int t = in();
	while(t--) solve();
	// auto ed = chrono::system_clock::now();
	// debug("time used = %.6lf\n", chrono::duration<double>(ed - st).count());
	// debug("totn = %d\n", tot);
	return 0;
}
