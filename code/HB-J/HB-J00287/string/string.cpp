#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], b[200005], ans;
char c[200005], d[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b[n - i + 1] = a[i];
		d[n - i + 1] = c[i];
	}
	int p = 1;
	for (int i = 1; i <= n; i++) {
		int sum = b[p], rem = 0;
		while (sum < a[i]) {
			ans += b[p] * (c[i] != d[p]);
			sum += b[++p];
		}
		rem = a[i] - (sum - b[p]);
		ans += rem * (c[i] != d[p]);
		b[p] = sum - a[i];
	}
	cout << ans / 2;
	return 0;
}
/*
3
2 a
2 b
1 a

1 a
2 b
2 a

1
*/
