#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define ft first
#define sd second
#define eb emplace_back
#define pb push_back
template<class T> inline void gmax(T& x, T y) {if (x < y) x = y;}
template<class T> inline void gmin(T& x, T y) {if (x > y) x = y;}
const int N = 500 + 10, M = 5e5 + 10, inf = 0x3f3f3f3f, mod = 998244353;
const ll linf = 0x3f3f3f3f3f3f3f3f;
inline void filo(string in, string out, int op = 3) {if (op & 1) freopen((in + ".in").c_str(), "r", stdin); if (op & 2) freopen((out + ".out").c_str(), "w", stdout);}
ll dis[N][N];
int w[M], id, n, m, d, q;
vector<pii> su[M];

int main() {
	filo("subway", "subway");
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> id >> n >> m >> d >> q, memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, a, t; j <= k; j++) cin >> a >> t, su[a].eb(i, t);
	}
	for (int i = 1; i <= m; i++) {
		int sz = su[i].size();
		for (int j = 0; j < sz; j++)
			for (int k = j + 1; k < sz; k++) {
				pii u = su[i][j], v = su[i][k];
				gmin(dis[u.ft][v.ft], 1ll * u.sd + v.sd);
				gmin(dis[v.ft][u.ft], 1ll * u.sd + v.sd);
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) gmin(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = linf;
		for (pii& u : su[x])
			for (pii& v : su[y]) gmin(ans, dis[u.ft][v.ft] + u.sd + v.sd);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
// 类似 floyd 一样维护两条线路最短距离，可以做到 O(n^3+d^2(m+q)) 
