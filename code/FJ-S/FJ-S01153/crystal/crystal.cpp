#include <iostream>
#include <algorithm>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)
#define N 500005
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f

int n, a[N], m, pre[N];
bool check(int x) {
	int l = 1, r = x, tmin = inf;
	while (r <= n) {
		int res = a[r] * x - (pre[r] - pre[l - 1]);
		if (res < tmin) {
			tmin = res;
		}
		l ++;
		r ++;
	}
	return tmin <= m;
}

signed main() {
	Write by ___NightDay___;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}
	int l = 0, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}

// 上午难下午简单是吧
// 100pts 
