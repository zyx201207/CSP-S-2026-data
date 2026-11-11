// difficulty: green / *1800
// tags: two pointers
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, p[200010], ans;
char c[200010];
int l, r, l_len, r_len, l_rem, r_rem;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i] >> c[i];
	l = 1, r = n;
	l_rem = p[1], r_rem = p[n];
	while (l < r) {
		int x = min(l_rem, r_rem);
		ans += x * (c[l] != c[r]);
		if (l_rem < r_rem) r_rem -= l_rem, l_rem = p[++l];
		else if (l_rem > r_rem) l_rem -= r_rem, r_rem = p[--r];
		else l_rem = p[++l], r_rem = p[--r];
	}
	cout << ans;
	return 0;
}
