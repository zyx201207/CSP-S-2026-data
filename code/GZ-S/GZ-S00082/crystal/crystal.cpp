//GZ-S00082 贵阳市第一实验中学 姚彦竹
#include <cstdio>
#include <algorithm>
#include <iostream>
typedef long long int ll;
using namespace std;
constexpr ll MAX = 5e5+10;
ll n, m, a[MAX], f[MAX], ans = 1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	bool flag = false;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) flag = true;
	}
	if (flag) {
		sort(a + 1, a + 1 + n);
	}
	f[1] = 0;
	ll l = 1, r = 1;
	while (l <= r && r + 1 <= n) {
		r++;
		f[r] = f[r - 1] + (a[r] - a[r - 1]) * (r - l);
		while (a[r + 1] == a[r]) {
			r++;
			f[r] = f[r-1];
		}
		if (f[r] > m) {
			while (f[r] > m && l < r) {
				f[r] -= a[r] - a[l]; l++;
			}
		}
		if (r - l + 1 > ans) ans = r - l + 1;
	}
	cout << ans;
	return 0;
}
