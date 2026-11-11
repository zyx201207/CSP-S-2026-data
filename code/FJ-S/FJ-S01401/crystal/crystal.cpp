#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, ans, a[500005], s[500005];

bool check(int p, int x) {
	int need = s[x] - s[p] - (p - 1) * (a[x] - a[p]);
	return (need <= m);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++) {
		s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for(int x = 1;x <= n;x ++) {
		int l = 1, r = x, pos = x;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid, x)) {
				r = mid - 1;
				pos = mid;
			}else {
				l = mid + 1;
			}
		}
		ans = max(ans, x - pos + 1);
	}
	cout << ans << "\n";
	return 0;
}
