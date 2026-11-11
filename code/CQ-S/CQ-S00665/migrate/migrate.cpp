#include<bits/stdc++.h>
#define rep(i, x, y) for(int i = (x); i <= (y); ++i)
#define drep(i, x, y) for(int i = (x); i >= (y); --i)
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) (A).begin(), (A).end()
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using i64 = long long;
template<typename T> inline void cmax(T &x, const T &y) { x = (x < y ? y : x); }
template<typename T> inline void cmin(T &x, const T &y) { x = (x < y ? x : y); }
const int N = 2e6 + 5;
int tsk_id, T, n, pr[N], pl[N];
i64 D, x[N];
vector<int> G[N];
//inline void dfs(int u) {
//	
//	for(int &v : G[u]) {
//		dfs(v);
//	}
//}
const int SZ = 305;
int f[SZ][SZ], c[SZ][SZ];
inline void sol1() {
	memset(f, 0x3f, sizeof f);
	memset(c, 0, sizeof c);
	rep(i, 1, n) {
		rep(j, i + 1, n) {
			if(x[j] - x[i] <= D) {
				f[i][j] = c[i][j] = 1;
			}
		}
	}
	rep(k, 1, n) rep(i, 1, k - 1) rep(j, k + 1, n) {
		if(f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j], c[i][j] = 0;
		c[i][j] += (f[i][j] == f[i][k] + f[k][j] ? (c[i][k] * c[k][j]) : 0), cmin(c[i][j], 3);
	}
	int ans = 0;
	rep(i, 1, n) {
		rep(j, i + 1, n) if(c[i][j] == 2) ++ans; //cout << "dbug : " << i << ' ' << j << '\n';
//		rep(j, i + 1, n) if(c[i][j] == 1) ++ans, cout << "1st : " << i << ' ' << j << '\n';
//		int x = i;
//		while(pr[x] ^ x) cout << "ps : " << i << ' ' << pr[x] << '\n', x = pr[x];
	}
	cout << ans << '\n';
}
inline void solve() {
	cin >> n >> D;
	rep(i, 1, n) cin >> x[i], G[i].clear();
	rep(i, 1, n) {
		pr[i] = max(pr[i - 1], i);
		while(pr[i] < n && x[pr[i] + 1] - x[i] <= D) ++pr[i];
		if(pr[i] ^ i) G[pr[i]].pb(i);
	}
	pl[n + 1] = n + 1;
	drep(i, n, 1) {
		pl[i] = min(pl[i + 1], i);
		while(pl[i] > 1 && x[i] - x[pl[i] - 1] <= D) --pl[i];
	}
	if(n <= 300) return sol1();
	else {
		if(tsk_id >= 11 && tsk_id <= 12) {
			
			return;
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	fastio, cin >> tsk_id >> T;
	while(T--) solve(); return 0;
}
