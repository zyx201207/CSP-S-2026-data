#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;

using PII = pair<int, int>;
using PLL = pair<ll, ll>;

#define fi first
#define se second

#define rep(i, j, k) for (int (i) = (j); (i) < (k); (i)++)
#define __rep(i, j, k) for (int (i) = (j); (i) <= (k); (i)++)
#define __rrep(i, j, k) for (int (i) = (j); (i) >= (k); (i)--)

constexpr ll inf = (1ll << 62);
constexpr int N = 2e6 + 10;

template <typename T> void chkmax(T& a, T b) { a = max(a, b); }
template <typename T> void chkmin(T& a, T b) { a = min(a, b); }

int n, to[N], g[N], rg[N];
ll d, x[N], f[N][2];

void add(int L, int R, ll x, int id) {
	f[L][id] += x;
	f[R + 1][id] -= x;
}

void solve() {
	cin >> n >> d;
	__rep(i, 1, n) {
		cin >> x[i];
	}
//	__rep(i, 0, n + 1) {
//		to[i] = 0;
//		f[i][0] = f[i][1] = 0;
//	}
//	f[0][0] = 1;
	
//	__rep(i, 1, n) {
//		f[i][0] += f[i - 1][0];
//		f[i][1] += f[i - 1][1];
//		int l = i + 1, r = n;
//		while (l < r) {
//			int mid = l + r + 1 >> 1;
//			if (x[mid] - x[i] <= d) l = mid;
//			else r = mid - 1;	
//		}
//		
//		to[i] = l;
//		if (to[i] == i) continue;
//		cerr << l << " \n"[i == n - 1];
//		int L = to[i - 1], R = to[i];
//		if (L < R) {
//			add(max(i + 1, L + 1), R, f[i][0], 0);
//			add(max(i + 1, L + 1), R, f[i][1], 1);
//		} else {
//			if (i < 2 || to[i - 2] < L) {
//				cerr << i << " !\n";
//				if (L - to[i - 2] <= d && (i <= 2 || to[i - 3] < i - 1)) {
//					
//				} else {
//					add(max(i + 1, to[i - 2] + 1), R, f[i][0] - 1, 1);	
//				}
//			}
//			add(max(i + 1, L), R, 1, 0);
//		}
//	}
	
//	ll ans = 0;
//	__rep(i, 1, n) {
//		ans += f[i][1];
//	}
//	cout << ans << "\n";

	__rep(i, 0, n + 1) {
		g[i] = rg[i] = 0;
	} 

	__rep(i, 1, n) {
		g[i]++;
		int l = i, r = n;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (x[mid] - x[i] <= d) l = mid;
			else r = mid - 1;	
		}
		
		to[i] = l;
		if (l > i && to[i - 1] < to[i]) {
			g[l] += g[i];
		}
	}
	__rrep(i, n, 1) {
		rg[i]++;
		if (to[i] > i && to[i - 1] < to[i]) {
//			cerr << i << "!\n";
			rg[i] += rg[to[i]];
			rg[i] += to[i] - to[i - 1];
		}
	}
	
	ll ans = 0;
	__rep(i, 2, n) {
		__rep(j, max(i + 1, to[i - 2] + 1), to[i]) {
			if (to[i - 1] < j) break;
			if (j < to[i]) {
//				cerr << i << " " << j << " " << g[i] - 1 << " !1\n";
				ans += g[i] - 1;
			} else {
//				cerr << i << " " << j << " " << (g[i] - 1) * rg[to[i]] << " !2\n";
				ans += (g[i] - 1) * rg[to[i]];
			}
		}	
	}

//	__rep(i, 1, n) {
//		cerr << g[i] << " \n"[i == n];
//	}
//	__rep(i, 1, n) {
//		cerr << rg[i] << " \n"[i == n];
//	}
	
	cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, t = 1;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}
