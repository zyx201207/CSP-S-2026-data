// lichenxi108.rp = inf, JCer.rp = -inf;
// 也许这是最后一战了。I won't AFO.
// 我该在哪里停留？我问我自己。

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, tmp;
long long a[N];

bool cmp(int x, int y) {
	for (int i = tmp; i >= 0; i--) {
		if ((x & (1 << i)) != (y & (1 << i))) {
			return (x & (1LL << i)) > (y & (1LL << i));
		}
	}
	return 0;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int r = n, ans = 0;
	for (int i = 29; i >= 0; i--) {
		tmp = i;
		sort(a + 1, a + r + 1, cmp);
		if (r < m || !(a[m] & (1LL << i))) continue;
		int k = r;
		for (int j = m; j <= r; j++) {
			if (!(a[j] & (1LL << i))) {
				k = j - 1;
				break;
			}
		}
		if (k < m) continue;
		r = k;
		ans ^= (1LL << i);
	}
	cout << ans;
	return 0;
} 
