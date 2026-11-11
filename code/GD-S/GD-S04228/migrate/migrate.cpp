#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
const int N = 5005, inf = 3e18;
using namespace std;

int c, T;
int n, D;
int d[N][N], cnt[N][N];
int x[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> D;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		x[n + 1] = inf;
		
		int r = n + 1, R, ans = 0;
		for (int i = n; i >= 1; i--) {
			while (x[r] - x[i] > D)
				r--;
			if (r == i) {
				R = i;
				continue;
			}
			
			for (int j = i + 1; j <= r; j++)
				d[i][j] = 1, cnt[i][j] = 1;
			for (int j = r + 1; j <= R; j++) {
				d[i][j] = d[r][j] + 1;
				cnt[i][j] = cnt[r][j];
				for (int k = r - 1; k > i; k--) {
					if (d[k][j] == d[r][j])
						cnt[i][j]++;
					if (cnt[i][j] > 2)
						break;
				}
				if (cnt[i][j] == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
