#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5 * 1e5 + 5;
int n,cnt,ans,ans2;
ll m,res;
ll a[N];
ll d[N];

int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 2; i <= n; ++i) {
		d[i - 1] = a[i] - a[i - 1];
	}
	int l = 1;
	for (int r = 2; r <= n; ++r) {
		res += (r - l) * (d[r - 1]);
		if (res <= m) {
			ans2 = r;
			if (ans2 >= ans) ans = ans2;
		} else {
			ll remain = 0;
			int ans1 = 0;
			while (l <= r && r <= n && l <= n) {
				++cnt;
				remain += a[r] - a[l];
				r--;
				res -= remain;
				remain = (m - res);
				l++,r++;
				while  (remain >= 0 && r <= n && l <= n && l <= r) {
					remain -= (r - l) * (d[r - 1]);
					if (remain < 0) {
						break;
					}
					res += (r - l) * (d[r - 1]);
					if (a[r] == a[r + 1] && r <= n - 1) r++;
					ans1 = r - l + 1;
					if (ans1 >= ans) ans = ans1;
					r++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
