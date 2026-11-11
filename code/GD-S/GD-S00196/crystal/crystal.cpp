#include<bits/stdc++.h>
using namespace std;

const int N = 500100;

int n;
long long m, a[N], sum[N];

inline bool check(int x, int now, int len) {
	if (len * a[now] * 1LL - (sum[now] - sum[x - 1]) > m)
		return false;
	return true;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i, mid = ((l + r) / 2);
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid, i, r - mid + 1))
				r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - l + 1);
//		cout << "is " << ans << " " << mid << endl;
	}
//	cout << n * a[n] * 1LL - sum[n] << " " << m << endl;
	cout << ans;
	return 0;
}
