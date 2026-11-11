// 100 
// nb, shuang le
// 15:08 huile
// 15:12 code done
// 15:22 check done
// CCF !!!!!!! 
// CCF computer fast
// 4e7+1.25e8+1e7 should pass
// Yellow/Green
// I'm vegetable 
#include <bits/stdc++.h>
using namespace std;
#define int ll
using ll = long long; using pi = pair<int, int>;
#define Fr(i, s, t) for (int i(s); i <= (t); ++i)
#define Bk(i, t, s) for (int i(t); i >= (s); --i)
inline int rd() {
	int x(0), f(1), c; while ((c = getchar()) < 48 || c > 57) f = c ^ 45;
	do x = x * 10 + (c & 15); while ((c = getchar()) > 47 && c < 58); return f ? x : -x;
}
constexpr int N = 510, M = 5e5 + 10;
int ccccc, n, m, d, q, w[M], dis[N][N];
vector<pi> vc[M]; 
inline void Main() {
	memset(dis, 0x3f, sizeof dis);
    ccccc = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    Fr(i, 1, m) w[i] = rd();
    Fr(i, 1, n) {
    	int k = rd();
    	while (k--) {
    		int a = rd(), d = rd();
    		vc[a].emplace_back(i, d);
		}
	}
	Fr(i, 1, m) {
		const vector<pi> &e = vc[i];
		for (const auto &[v, w] : e) for (const auto &[s, t] : e) {
			if (v == s) continue;
			dis[v][s] = dis[s][v] = w + t;
		}
	}
	Fr(i, 1, n) dis[i][i] = 0;
	Fr(k, 1, n) Fr(i, 1, n) Fr(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//	Fr(i, 1, n) { Fr(j, 1, n) cerr << dis[i][j] << ' '; cerr << '\n'; }
	while (q--) {
		int x = rd(), y = rd(), ans = 1e18;
		for (const auto &[v, w] : vc[x]) for (const auto &[s, t] : vc[y]) {
	//		cerr << v << ' ' << s << ' ' << dis[v][s] << ' ' << w << ' ' << t << endl;
			ans = min(ans, dis[v][s] + w + t);
		}
		ans += w[x] + w[y];
		printf("%lld\n", ans);
	} 
} signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Bk(T, 1, 1) Main();
}

