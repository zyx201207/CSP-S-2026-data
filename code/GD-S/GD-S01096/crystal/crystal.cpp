#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 5e5 + 10;

int n, m, ans = 1;
int a[maxn], s[maxn];

bool ck(int l, int r) {
	return ((r - l + 1) * a[r] - (s[r] - s[l - 1]) <= m);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for (int i = 1, l, r, mid; i <= n; ++i) {
		l = 1, r = i;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (ck(mid, i)) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
