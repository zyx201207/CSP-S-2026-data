#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, T, n, L[N], R[N];
ll d, x[N], f[N], sum[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) {
			int l = 1, r = i - 1, ans = 0;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (x[i] - x[mid] <= d) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			if (ans) L[i] = ans, R[i] = i - 1;
			else L[i] = 1e9, R[i] = -1e9;
		}
		ll ans = 0;
		for (int s = 1; s <= n; s++) {
			f[s] = 1, sum[s - 1] = 0, sum[s] = 1; int l = s, r = s;
			for (int j = s + 1; j <= n; j++) {
				if (x[r] + d < x[j]) l = r + 1, r = j - 1;
				int tl = max(l, L[j]), tr = r;
				if (tl <= tr) f[j] = sum[tr] - sum[tl - 1];
				else f[j] = 0;
				if (f[j] == 2) ans++;
				sum[j] = sum[j - 1] + f[j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}