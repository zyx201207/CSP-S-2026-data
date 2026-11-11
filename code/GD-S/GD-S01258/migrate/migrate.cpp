#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
int c , t;
int n , d;
int a[N] , cnt[N][N] , dist[N][N];
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out", "w" , stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j || i == k || j == k) continue;
					if (abs(a[i] - a[k]) <= d) {
						if (dist[i][k] > 1) cnt[i][k] = 0;
						cnt[i][k]++;
						dist[i][k] = 1;
					}
					if (abs(a[k] - a[j]) <= d) {
						if (dist[k][j] > 1) cnt[k][j] = 0;
						cnt[k][j]++;
						dist[k][j] = 1;
					}
					if (abs(a[i] - a[j]) <= d) {
						if (dist[i][j] > 1) cnt[i][j] = 0;
						cnt[i][j]++;
						dist[i][j] = 1;
					} else {
						if (dist[i][j] > dist[i][k] + dist[k][j]) {
							dist[i][j] = dist[i][k] + dist[k][j];
							cnt[i][j] = 1;
						}
					}
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cnt[i][j] == 2) sum++;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
