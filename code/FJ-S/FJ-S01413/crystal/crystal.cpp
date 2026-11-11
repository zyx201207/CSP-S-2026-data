#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
int zmx[N];
int qzh[N];
int dj(int l,int r) {
	int ans = qzh[r] - qzh[l - 1];
	int dc = zmx[r] * (r - l + 1);
	return ans - dc;
}
bool check(int mid) {
	bool b = 0;
	for (int i = 1; i <= n - mid + 1; i++) {
		int sum = dj(i, i + mid - 1);
		if (sum <= m) return 1;
	}
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		zmx[i] = a[n] - a[i];
		qzh[i] = zmx[i] + qzh[i - 1];
	}
	int l = 0, r = n + 1, ans;
	while(l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			;
			r = mid - 1;
		}
	}
	if (check(r)) ans = max(ans, r);
	if (check(l)) ans = max(ans, l);
	printf("%lld\n", ans);
	return 0;
}
