// 100

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kM = 5e5 + 7;

int n, m, a[kM], b[kM], maxn = -1e18, ans = -1, l, r, sum[kM];

bool check(int mid, int i) { // mid~i<=m?
//	if (i - x <= 0) x = i - 1;
	int qs = sum[i] - sum[mid - 1];
	int ying = (i - mid + 1) * a[i];
//	cout << "qs = " << qs << "    ying = " << ying << "\n";
	if (qs + m >= ying) return 1;
	else return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	} 
	for (int i = 1; i <= n; i++) {
		l = 1, r = i;
		int cnt = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) {
				cnt = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
//		cout << "cnt = " << i - cnt + 1 << " \n";
		ans = max(ans, i - cnt + 1);
	}
	cout << ans;
//	cout << check(1, 4);
	return 0;
}

/*
5 5
1 2 4 8 9

*/
