#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
long long c, t, x[N], l[N], r[N], cnt[N], f[N], r_ed[N];
long long n, d;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
			cin >> x[i];
		for (int i = 1, j = 1; i <= n; i ++) {
			while (j <= n && x[j] - x[i] <= d)
				j ++;
			r[i] = j - 1;
		}
		for (int i = n, j = n; i; i --) {
			while (j && x[i] - x[j] <= d)
				j --;
			l[i] = j + 1;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			memset(f, 0x3f, sizeof f);
			memset(cnt, 0, sizeof cnt);
			f[i] = 0, cnt[i] = 1;
			for (int j = i; j <= n; j ++)
				for (int k = j + 1; k <= r[j]; k ++) {
					if (f[k] > f[j] + 1)
						f[k] = f[j] + 1, cnt[k] = cnt[j];
					else if (f[k] == f[j] + 1)
						cnt[k] += cnt[j];
				}
			for (int j = i; j <= n; j ++)
				ans += cnt[j] == 2;
		}
		cout << ans << "\n";
	}
	return 0;
}

