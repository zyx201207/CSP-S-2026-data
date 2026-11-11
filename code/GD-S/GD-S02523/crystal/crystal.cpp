#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];
int sum[N];

inline int find(int i) {
	int res = i;
	for (int l = 1, r = i; l <= r;) {
		int mid = l + ((r - l) >> 1);
		int q = sum[i] - sum[mid - 1];
		int tsum = a[i] * (i - mid + 1);
		if (tsum - q <= m) {
			r = (res = mid) - 1;
		} else {
			l = mid + 1;
		}
	}
	return i - res + 1;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, find(i));
	}
	
	cout << ans << endl;
	
	return 0;
}
