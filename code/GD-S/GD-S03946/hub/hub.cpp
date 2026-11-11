#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

const int N = 1005;
int Sub, Cas, n, k, f[N], g[N]; pii edg[N];
vector<int> G[N], T[N], Ver;

void init() { for(int u : Ver) T[u].resize(0); Ver.resize(0); }
void build(int u, int fa) { Ver.eb(u); for(int v : G[u]) if(v != fa) T[u].eb(v), T[v].eb(u), build(v, u); }

int mxdp[N], cnt[N];
void dfs(int u, int fa, int *cnt) {
	mxdp[u] = 0;
	for(int v : T[u]) if(v != fa) {
		dfs(v, u, cnt);
		mxdp[u] = max(mxdp[u], mxdp[v] + 1);
	} cnt[mxdp[u]]++;
}
void solve(int *f) {
	int nd = (int)Ver.size();
	for(int i = 0; i <= n; i++) f[i] = 1e9;
	for(int u : Ver) {
		for(int i = 0; i <= nd + 1; i++) cnt[i] = 0;
		dfs(u, 0, cnt);
		for(int i = nd; ~i; i--) {
			cnt[i] += cnt[i + 1];
			f[i] = min(f[i], cnt[i]);
		}
	}
}

void mian() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, G[u].eb(v), G[v].eb(u), edg[i] = pii(u, v);
	init(), build(1, 0), solve(f);
	int res = 0;
	for(int i = 0; i <= n; i++) if(k >= f[i]) { res = i; break; }
	for(int e = 1; e < n; e++) {
		auto [u, v] = edg[e];
		init(), build(u, v), solve(f);
		init(), build(v, u), solve(g);
		for(int i = 0; i <= n; i++) if(k >= f[i] + g[i]) { res = min(res, i); break; }
	} cout << res << '\n';
}

int main() {
	file(hub);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> Sub >> Cas;
	while(Cas--) mian();
	cout << flush;
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

0 1
5 2
1 2
2 3
3 4
4 5
*/

