#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
ll dp[N][N][2];
ll a[N];
bool m[N][N];
ll ls[1];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	memset(ls, 0x3f, sizeof ls);
	ll maxx = ls[0];
	int c, t;
	cin >> c >> t;
	while(t -- ) {
		ll n, d, ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++ ) cin >> a[i];
		for(int i = 1; i <= n; i ++ ) {
			for(int j = i + 1; j <= n; j ++ ) {
				m[i][j] = 0;
				if(a[j] - a[i] <= d) m[i][j] = 1;
			}
		}
		for(int i = 1; i <= n; i ++ ) {
			for(int j = 1; j <= n; j ++ ) {
				dp[i][j][0] = maxx;
				dp[i][j][1] = 0;
			}
		}
		for(int i = 1; i <= n; i ++ ) {
			for(int j = i + 1; j <= n; j ++ ) {
				if(m[i][j] == 1) {
					dp[i][j][0] = dp[i][j][1] = 1;
				}
			}
		}
		for(int l = 2; l < n; l ++ ) {
			for(int i = 1; i < n; i ++ ) {
				int j = l + i;
				if(j > n) break ;
				for(int k = i + 1; k < j; k ++ ) {
					ll now = dp[i][k][0] + dp[k][j][0];
					if(now == dp[i][j][0]) dp[i][j][1] ++ ;
					else if(now < dp[i][j][0]) {
						dp[i][j][0] = now;
						dp[i][j][1] = 1;
					}
				}
			}
		}
		for(int i = 1; i < n; i ++ ) {
			for(int j = i + 2; j <= n; j ++ ) {
				if(dp[i][j][1] == 2) {
					ans ++ ;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
