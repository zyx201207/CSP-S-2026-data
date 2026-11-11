#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, num, a[N], cnt, ans;
char c, st[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num >> c;
		if (c == st[cnt]) a[cnt] += num;
		else {
			cnt++;
			st[cnt] = c;
			a[cnt] = num;
		}
	}
	for (int l = 1, r = cnt; l < r; ) {
		long long pos = min(a[l], a[r]);
		a[l] -= pos;
		a[r] -= pos;
		if (st[l] != st[r]) ans += pos;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	}
	cout << ans;
	return 0;
}
