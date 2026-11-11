#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll n, m, ans, a[N], s[N];

int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i ++) {
		ll l = 1, r = i, mid;
		while (l < r) {
			mid = (l + r) >> 1;
			ll now = a[i] * (i - mid) - (s[i - 1] - s[mid - 1]);
			if (now > m) l = mid + 1;
			else {
				ans = max(ans, i - mid + 1);
				r = mid;
			} 
		}
	}
	cout << ans;
	return 0;
}

