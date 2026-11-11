// GZ-S00256 ≥¬Í≈÷Ò 
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6+10, INF = 0x3f3f3f3f3f3f3f3f;
int c, T;
int n, D;
int a[N];
int d[3000][3000], cnt[3000][3000], ans;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> T;
	while(T--) {
		cin >> n >> D;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if(c <= 10) {
			ans = 0;
			memset(d, 0x3f, sizeof(d));
			memset(cnt, 0, sizeof(cnt));
			for(int i = 1; i <= n; i++) {
				for(int j = i+1; j <= n; j++) {
					if(a[j] - a[i] <= D) {
						d[i][j] = d[j][i] = 1;
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					for(int k = 1; k <= n; k++) {
						if(d[i][j] > d[i][k] + d[k][j]) {
							d[i][j] = d[i][k] + d[k][j];
						} else if(d[i][j] == d[i][k] + d[k][j]) {
							cnt[i][j]++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				for(int j = i+1; j <= n; j++) {
					if(cnt[i][j] == 1) ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
