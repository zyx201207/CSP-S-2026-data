#include <bits/stdc++.h>

#define _for(i, a, b) for (int i = (a); i <= (b); i ++ )

using namespace std;

typedef long long LL;
const int N = 2e6 + 10;
int n, C, T;
LL x[N], f[N], g[N], ans, dd;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> T;
	if (C <= 10) {
		while (T -- ) {
			ans = 0;
			cin >> n >> dd;
			_for (i, 1, n) cin >> x[i];
			for (int i = n - 1; i; i -- ) {
				_for (j, i, n) f[j] = g[j]= 0;
				f[i] = 0, g[i] = 1;
				LL sum = 1, d = 0, l = i;
				_for (j, i + 1, n) {
					while (x[j] - x[l] > dd) {
						sum -= g[l];
						l ++;
					}
					if (l == j) break;
					if (d != f[l]) {
						d = f[l], sum = 0;
						int t = l;
						while (t < j && f[t] == d) {
							sum += g[t ++ ];
						}
					}
					f[j] = d + 1, g[j] = min(3ll, sum);
					if (g[j] == 2) ans ++;
					// cout << i << ' ' << j << ' ' << f[j] <<' ' << g[j] << '\n';
				}
			}
			cout << ans << '\n';
		}
	}
	else if (C <= 12){
		while (T -- ) {
			cin >> n >> dd;
			_for (i, 1, n) cin >> x[i];
			if (n == 1) cout << "0\n";
			else {
				LL gc = x[2] - x[1], p = dd/ gc;
				if (p <= 1) cout << "0\n";
				else {
					LL k = 2 * p - 1;
					cout << max(0ll, n - k) << '\n';
				}
			}
		}
		return 0;
	}
	else {
		while (T -- ) {
			cin >> n >> dd;
			_for (i, 1, n) cin >> x[i];
			int pos;
			ans = 0;
			_for (i, 1, n) if (x[i] - x[1] <= dd && x[n] - x[i] <= dd) pos = i;
			_for (i, 1, pos - 1) {
				int l = pos, r = n;
				while (l < r) {
					int mid = l + r + 1>> 1;
					if (x[mid] - x[i] <= dd) l = mid;
					else r = mid - 1;
				}
				if (l > pos + 1) continue;
				else if (l == pos) {
					if (pos <= 2 || i == pos - 1) continue;
					int nl = pos, nr = n;
					while (nl < nr) {
						int mid = nl + nr + 1 >> 1;
						if (x[mid] - x[pos - 1] <= dd) nl = mid;
						else nr = mid - 1;
					}
					int ml = pos, mr = n;
					while (ml < mr) {
						int mid = ml + mr + 1 >> 1;
						if (x[mid] - x[pos - 2] <= dd) ml = mid;
						else mr = mid - 1;
					}
					ans += max(0, nl - ml);
				}
				else {
					int nl = pos, nr = n;
					while (nl < nr) {
						int mid = nl + nr + 1 >> 1;
						if (x[mid] - x[pos - 1] <= dd) nl = mid;
						else nr = mid - 1;
					}
					ans += max(0, n - nr);
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
