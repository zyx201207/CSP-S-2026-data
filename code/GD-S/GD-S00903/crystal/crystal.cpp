#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[514514];
int qz[514514];
map <int,int> cnt;

bool check(int l,int r) {
	return a[r] * (r - l) - qz[r - 1] + qz[l - 1] <= m;
}

int calc(int k) {
	int l = 1,r = k - 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid,k)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (check(l,k)) return k - l;
	if (check(r,k)) return k - r;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++) {
		qz[i] = qz[i - 1] + a[i];
	}
	a[0] = -1e18;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) continue;
		res = max(res,calc(i) + cnt[a[i]]);
	}
	cout << res;
	return 0;
}
