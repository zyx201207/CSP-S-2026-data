#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define MAXN 500005
using namespace std;
int n, m, a[MAXN], sum[MAXN], cost, ans = 0, tmp;
inline int find(int, int, int, int);
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	sum[0] = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (a[1] < 0) tmp = -a[1];
	sum[0] = 0;
	for (int i = 1;i <= n;i++) {
		a[i] += tmp;
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1;i <= n;i++){
		ans = max(ans, i - find(1ll, i, m, i) + 1);
	}
	cout << ans;
	return 0;
}
inline int find(int l, int r, int m, int i){
	int mid = (l + r) >> 1;
	while(l < r) {
		mid = (l + r) >> 1;
		if (a[i] * (i - mid) - sum[i - 1] + sum[mid - 1] < m) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return mid;
}