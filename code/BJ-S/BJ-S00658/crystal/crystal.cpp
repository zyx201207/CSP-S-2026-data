#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

LL n, m;
LL a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	sort(a, a + n);
	a[n] = 0x7fffffffffffffff;
	int l = 0, r = 0;
	int ans = 0;
	int now = 0;
	while (r < n) {
		if (l > r) r = l;
		ans = max(r - l + 1, ans);
		if ((a[r + 1] - a[r]) * (r - l + 1) <= m - now) {
			now += (a[r + 1] - a[r]) * (r - l + 1);
			r ++ ;
		} else {
			now -= a[r] - a[l];
			l ++ ;
		}
	}
	cout << ans << endl;
	return 0;
}
