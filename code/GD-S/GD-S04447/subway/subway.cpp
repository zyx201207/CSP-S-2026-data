#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
using ll = long long;
char buf[1 << 20], *p1 = buf, *p2 = buf;
char gc(void) {
	if(p1 == p2) p1 = buf, p2 = buf + fread(buf, 1, 1 << 20, stdin);
	return *p1++;
}
int in(void) {
	int x = 0; char c = gc();
	while(!isdigit(c)) c = gc();
	while(isdigit(c)) x = x * 10 + c - '0', c = gc();
	return x;
}
// int in(void) { int x; scanf("%d", &x); return x; }
// ll inl(void) { ll x; scanf("%lld", &x); return x; }
using namespace std;
// auto st = chrono::system_clock::now();
using pii = pair<int,int>;
int n, m, d, q;
const int kN = 505, kM = 505000;
int w[kM];
vector<pii> g[kM];
ll G[kN][kN];
inline void chkmin(ll &a, ll b) { a = min(a, b); }
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	in(), n = in(), m = in(), d = in(), q = in();
	_rep(i,1,m) w[i] = in();
	_rep(i,1,n) {
		int k = in();
		while(k--) {
			int a = in(), b = in();
			g[a].emplace_back(i, b);
		}
	}
	memset(G, 0x3f, sizeof(G));
	_rep(i,1,m) for(int j = 0; j < g[i].size(); ++j) for(int k = j + 1; k < g[i].size(); ++k) 
		chkmin(G[g[i][j].first][g[i][k].first], g[i][j].second + g[i][k].second);
	_rep(i,1,n) G[i][i] = 0;
	_rep(i,1,n) _rep(j,1,n) {
		ll v = min(G[i][j], G[j][i]);
		G[i][j] = G[j][i] = v;
	}
	_rep(k,1,n) _rep(i,1,n) _rep(j,1,n) chkmin(G[i][j], G[i][k] + G[k][j]);
	_rep(i,1,q) {
		int u = in(), v = in();
		ll ans = 1e18;
		for(auto &[a, b] : g[u]) for(auto &[c, d] : g[v]) chkmin(ans, G[a][c] + b + d);
		printf("%lld\n", ans + w[u] + w[v]);
	}
	// auto ed = chrono::system_clock::now();
	// debug("time used = %.6lf\n", chrono::duration<double>(ed - st).count());
	return 0;
}