//t3 rp += inf
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e3 + 10;
ll n, d, a[N], dp[N][N], dp2[N][N];
int rch[N];

inline void Solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		rch[i] = i;
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] - a[i] <= d) rch[i] = j;
			else break;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	memset(dp2, 0, sizeof(dp2));
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i + k - 1 <= n; ++i) {
			int j = i + k - 1;
			if(rch[i] >= j) {
				dp[i][j] = 1;
				continue;
			}
			for (int l = i + 1; l < j; ++l) {
				dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j]);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= rch[i]; ++j) 
			dp2[i][j] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = rch[i] + 1; j <= n; ++j) {
			for (int l = i + 1; l < j; ++l) {
				if (dp[i][l] + dp[l][j] == dp[i][j])
					dp2[i][j] += dp2[i][l] * dp2[l][j];
			}
			if (dp2[i][j] == 2) ans++;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Tid, T;
	cin >> Tid >> T;
	while (T--) Solve(); 
	return 0;
} 
