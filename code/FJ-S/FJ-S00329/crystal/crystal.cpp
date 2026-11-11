#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, ans = 0, a[N], pre[N];
int check(int x) {
	int L = 1, R = x;
	int sum = -1;
	while(L < R) {
		int mid = L + (R - L) / 2;
		int cnt = x - mid + 1;
		int need = a[x] * cnt, now = pre[x] - pre[mid - 1];
		if(need - now <= m) {
			R = mid, sum = mid;
		} else L = mid + 1;
	}
	return sum;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		ans = max(ans, i - check(i) + 1);
	}
	cout << ans;
	return 0;
}
