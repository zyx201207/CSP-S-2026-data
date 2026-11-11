#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int, int>
using namespace std;
const int N = 1000010;
const int inf = 1e18;
int f[1100][1100], sum[1100][1100];
int x[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t --) {
		int n, d;
		cin >> n >> d;
		For(i, 1, n) cin >> x[i];
		memset(f, 0x3f, sizeof(f));
		memset(sum, 0, sizeof(sum));
		For(i, 1, n) {
			For(j, i, n) {
				f[i][j] = (x[j] - x[i] > d) ? inf : x[j] - x[i];
			}
		}
		For(k, 1, n) {
			For(i, 1, n) {
				For(j, 1, n) {
					if(i <= k && k <= j) {
						if(f[i][k] + f[k][j] < f[i][j]) {
							sum[i][j] = 1;
							f[i][j] = f[i][k] + f[k][j];
						} else if(f[i][k] + f[k][j] == f[i][j] && f[i][j] != inf) {
							sum[i][j] ++;
						}
					}
				}
			}
		}
		int ans = 0;
		For(i, 1, n) {
			For(j, i + 1, n) {
				if(sum[i][j] >= 2) {
					For(i, 1, sum[i][j] - 1) {
						ans += sum[i][j] - i;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
