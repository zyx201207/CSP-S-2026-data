#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
using namespace std;



namespace Sub1 {
	const int N = 5005, K = 1e8;
	
	long long x[N];
	pair <int, int> dp[N];
	
	int work () {
		long long T, n, d, ans;
		cin >> T;
		while (T--) {
			cin >> n >> d, ans = 0;
			rep (i, 1, n) cin >> x[i];
			rep (i, 1, n) {
				dp[i] = {1, 1};
				rep (j, i + 1, n) {
					dp[j] = {K, 0};
					irep (k, j - 1, i) {
						if (x[j] - x[k] > d) break;
						if (dp[k].first + 1 < dp[j].first) dp[j] = dp[k], ++dp[j].first;
						else if (dp[k].first + 1 == dp[j].first) dp[j].second = min (K, dp[j].second + dp[k].second);
					}
					if (dp[j].second == 2) ++ans;
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
}

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	int c;
	cin >> c;
	if (c <= 6) return Sub1 :: work ();
	return 0;
}
