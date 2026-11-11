#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
constexpr int MAXN = 2e6 + 9, INF = 0x3f3f3f3f3f3f3f3f;
int c, T, n, d;
int x[MAXN];

int L[MAXN], R[MAXN];
void init() {
	for(int i = 1, l = 1, r = 1; i <= n; i++) {
		while(r < n && x[r + 1] - x[i] <= d) r++;
		while(l < i && x[i] - x[l] > d) l++;
		L[i] = l, R[i] = r;
	}
}

int ans; pii dp[MAXN];
namespace P1 {
	void solve() {
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		init();
		for(int u = 1; u <= n; u++) {
			for(int i = 1; i <= n; i++) dp[i] = {INF, INF};
			dp[u] = {0, 1};
			for(int i = u + 1; i <= n; i++) {
				for(int l = max(u, L[i]); l < i; l++) {
					int p = dp[l].fi, q = dp[l].se;
					p++;
					if(dp[i].fi > p) dp[i] = {p, q};
					else if(dp[i].fi == p) dp[i].se += q; 
					else break;
				}
			}
			for(int i = u + 1; i <= n; i++) if(dp[i].se == 2) ans++;
		}
		cout << ans << '\n';
	}
}
namespace P2 {
	void solve() {
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		init();
		for(int u = 1; u <= n; u++) {
			for(int i = 1; i <= n; i++) dp[i] = {INF, INF};
			dp[u] = {0, 1};
			int l = u, r = u, sum = 1;
			for(int i = u + 1; i <= n; i++) {
				while(l < i && l < L[i]) {
					sum -= dp[l].se;
					l++;
				}
				while(r < l) {
					r++;
					sum += dp[r].se;
				}
				while(dp[r + 1].fi == dp[l].fi) {
					r++;
					sum += dp[r].se;
				} 
				dp[i] = {dp[l].fi + 1, sum};
			}
			for(int i = u + 1; i <= n; i++) if(dp[i].se == 2) ans++;
		}
		cout << ans << '\n';
	}
}
namespace P3 {
	void solve() {
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		init();
		for(int i = 1; i <= n; i++) dp[i] = {INF, INF};
		dp[1] = {0, 1};
		int l = 1, r = 1, sum = 1;
		for(int i = 2; i <= n; i++) {
			while(l < i && l < L[i]) {
				sum -= dp[l].se;
				l++;
			}
			while(r < l) {
				r++;
				sum += dp[r].se;
			}
			while(dp[r + 1].fi == dp[l].fi) {
				r++;
				sum += dp[r].se;
			} 
			dp[i] = {dp[l].fi + 1, sum};
		}
		for(int i = 2; i <= n; i++) if(dp[i].se == 2) ans++;
		int tmp = ans;
		for(int i = n; i > 1; i--) {
			if(dp[i].se == 2) tmp--;
			ans += tmp;
		}
		cout << ans << '\n';
	}
} 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		if(c <= 6) P1::solve();
		else if(c <= 10) P2::solve();
		else if(c <= 12) P3::solve();
	}
	return 0;
}

