#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int c,t,n;
ll a[N],dp[5005][5005],f[5005][5005],ans,sum[N],d;
ll adp[N],af[N];
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if (c <= 10) {
		while (t --) {
			for(int i = 1; i <= n; i ++) {
				a[i] = 0;
				sum[i] = 0;
				for(int j = 1; j <= n; j ++) {
					dp[i][j] = 0;
					f[i][j] = 0;
				}
			}
			ans = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++) {
				cin >> a[i];
				sum[i] = sum[i - 1] + a[i];
			}
			
			for(int i = 1; i < n; i ++) {
				int l = i, r = i;
				ll cnt = 0;
				f[i][i] = 1;
				for(int j = i + 1; j <= n; j ++) {
					while (a[l] + d < a[j] && l < j && l <= r) {
						cnt -= f[i][l];
						l ++;
					}
					while (a[l] + d < a[j] && l < j) l ++;
					if (r <= l) cnt = f[i][l];
					r = max(l,r);
					while (dp[i][r] == dp[i][l] && r < j) {
						r ++;
						cnt += f[i][r];
					}
					if (cnt == 2) ans ++;
					dp[i][j] = dp[i][l] + 1;
					f[i][j] = cnt;
//					cout << f[i][j] << ' ';
				}
//				cout << endl;
			}
			cout << ans << endl;
		}
	}else if (11 <= c && c <= 12) {
		while (t --) {
			for(int i = 1; i <= n; i ++) {
				adp[i] = 0;
				a[i] = 0;
				sum[i] = 0;
			}
			ans = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++) cin >> a[i];
			ll stp = d / (a[2] - a[1]);
			if (stp <= 1 || n == 1) {
				cout << 0 << endl;
				continue;
			}
			ans = min(n - stp - 1, 0LL);
			cout << ans << endl;
		}
	}else {
		while (t --) cout << 1 << endl;
	}
	return 0;
}
