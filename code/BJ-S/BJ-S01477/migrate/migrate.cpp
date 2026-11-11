#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 2;
int c, t, n;
long long dp[N][N], cnt[N][N], d, x[2000000 + 2];
void solve1() {
	// cout << "in" << endl;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		// cout << "n:" << n << " d:" << d << endl;
		long long gongcha = x[2] - x[1];
		long long cnt = d / gongcha;
		cnt++;
		// cout << "gongcha:" << gongcha << endl;
		// cout << "n:" << n << endl;
		// cout << "cnt:" << cnt << endl;
		if(cnt == 2 || cnt == 1 || cnt > n) cout << 0 << "\n";
		else cout << n - 2 * cnt + 3 << "\n";
		// cout << n - (cnt + 1) + 1 << "\n"; 
	}
	return;
}
int l[2000000 + 2], r[2000000 + 2];
map <int, int> mpr;
void solve2() {
	while(t--) {
		mpr.clear();
		// mpr.clear();
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		int p = 1;
		for(int v = 1; v <= n; v++) {
			while(p <= n && x[v] - x[p] > d) p++;
			l[v] = p;
			// mpl[p]++;
			r[v] = v;
			// mpr[v]++;
			/*/if(t == 1) {
				cout << "l:" << l[v] << " r:" << r[v] << endl;
			}/*/
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			// if(stop >= i) continue;
			if(r[i] - l[i] + 1  == 1 || r[i] - l[i] + 1 == 2 || r[i] - l[i] + 1 > n) continue;
			// ans += mpr[l[i] + 1];
			// ans += mpl[r[i] - 1];
			// cout << "l[i]:" << l[i] << " r[i]:" << r[i] << endl;
			ans += mpr[l[i] + 1];
			mpr[r[i]]++;
			// if(t == 1) cout << "i:" << i << ans << endl;
		}
		cout << ans << "\n";
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	// cout << "c:" << c << " t:" << t << endl;
	// solve2();
	// return 0; 
	if(11 <= c && c <= 12) {
		solve1();
		return 0;
	} else if(c > 12) {
		solve2();
		return 0; 
	}
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		memset(dp, 0x3f, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		for(int v = 1; v <= n; v++) {
			int tmp = v - 1;
			while(tmp && x[v] - x[tmp] <= d) {
				dp[tmp][v] = 1;
				cnt[tmp][v] = 1;
				// cout << "dp1:" << tmp << " " << v << endl;
				tmp--;
			}
		}
		for(int v = 1; v <= n; v++) {
			int tmp = v - 1;
			while(tmp && x[v] - x[tmp] <= d) {
				for(int u = 1; u <= tmp; u++) {
					if(dp[u][v] > dp[u][tmp] + 1) {
						dp[u][v] = dp[u][tmp] + 1;
						cnt[u][v] = cnt[u][tmp];
						// cout << "u:" << u << " v:" << v << " dp:" << dp[u][v] << " cnt:" << dp[u]
					} else if(dp[u][v] == dp[u][tmp] + 1) {
						cnt[u][v] += cnt[u][tmp];
					}
				}
				tmp--;
			}
		}
		/*/cout << "dp:" << endl;
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				cout << dp[u][v] << " ";
			}
			cout << endl;
		}
		cout << "cnt:" << endl;
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				cout << cnt[u][v] << " ";
			}
			cout << endl;
		}/*/
		int ans = 0;
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				if(cnt[u][v] == 2) ans++;
			}
		}
		// cout << "ans:" << endl;
		cout << ans << "\n";
	}
	return 0;
}