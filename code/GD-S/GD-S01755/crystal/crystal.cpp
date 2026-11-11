#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(n) cout << #n << " = " << n << '\n';
const int N = 5e5 + 10;
int n, m;
int a[N], s[N];

bool check(int i, int mid) {
//	deb(i);
//	deb(mid);
//	deb(a[i] * i - s[i] - s[mid - 1]);
	return a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
//	for (int i = 1; i <= n; i++) cout << i << ' ' << a[i] << ' ' << s[i] << '\n';
	
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, best = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(i, mid)) {
				r = mid - 1;
				best = mid;
			} else {
				l = mid + 1;
			}
		}
		if (best != -1) mx = max(mx, abs(i - best + 1));
	}
	cout << mx;
	return 0;
}
