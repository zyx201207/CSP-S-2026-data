#include <bits/stdc++.h>
using namespace std;

// RP++
// AC AC AC
// 图灵老祖助我一臂之力
// 图灵保佑 
// 
// 好无聊 (11:11) 
// dayz的time表太牢了 
// dayz class 850 的 ywb 和 js 是 (char)70 (char)101 (char)109 (char)98 (char)97 (char)121.

typedef long long ll;
const ll N = 2*1e5+5;

ll n, ans, k, a[N];
char c[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (ll i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
	}
	
	for (ll l=1, r=n; l <= r; ) {
		if (a[l] == a[r]) {
			if (c[l] != c[r]) {
				ans += a[l];
			}
			l++, r--;
		}
		else if (a[l] < a[r]) {
			if (c[l] != c[r]) {
				ans += a[l];
			}
			a[r] -= a[l];
			l++;
		}
		else {
			if (c[l] != c[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		}
	}
	
	cout << ans << "\n";

	return 0;
}

