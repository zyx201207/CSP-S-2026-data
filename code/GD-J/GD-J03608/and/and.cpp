#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, ans, a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 30; ~i; --i) {
		int c = 0;
		for (int j = 1; j <= n; ++j) {
			if ((a[j] & ans) == ans)
				c += a[j] >> i & 1;
		}
		ans |= (c >= m) << i;
	}
	return cout << ans, 0;
}
