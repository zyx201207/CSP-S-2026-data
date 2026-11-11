/**
 * @file CSP-J 2026
 *       Problem B. string
 * @author BJ-J01847
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/

// Causes my grief, petrichor
// Petrichor - void(Mournfinale)

// password: Trick||Treat!

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, a[N]; char c[N];
ll ans;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> c[i];
	int i = 1, j = n; ll t;
	while (i < j) {
		t = min(a[i], a[j]);
		if (c[i] != c[j])
			ans += t;
		a[i] -= t, a[j] -= t;
		i += (a[i] == 0);
		j -= (a[j] == 0);
	}
	cout << ans << '\n';
	return 0;
}

//08:57