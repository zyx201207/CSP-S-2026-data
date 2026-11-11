#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N], l1[N], r1[N], cnt, ret, n;
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int l = 1, r = n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	while (l < r) {
		int cur = min(a[l], a[r]);
		if (c[l] != c[r])
			ret += cur;
		a[l] -= cur;
		a[r] -= cur;
		if (!a[l])
			l++;
		if (!a[r])
			r--;
	}
	cout << ret << '\n';
	return 0;
}
