#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
ll a[N];
ll n, m;
/*
5 5
1 2 4 8 9

14:53 wa on pretest 3
ac on 1, 2, 4

14:57 all pretest accepted
*/

ll arr[N];


int main() {

	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll maxa = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i], maxa = max(maxa, a[i]);

	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i ++) arr[i] = arr[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		ll tar = a[i];
		int l = 1, r = i, mid;
		ll s, c;
//		cout << "#" <<i << "\n";
		while (l <= r) {
			mid = l + r >> 1;
			s = arr[i] - arr[mid - 1];
			c = 1ll * a[i] * (i - mid + 1) - s;
//			cout << mid << " " << s << " " << c << "\n";
			if (c <= m) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
//		cout << mid << "\n";
//		if (c <= m) ans = max(ans, i - mid + 1);
	}
	cout << ans;

	return 0;
}

