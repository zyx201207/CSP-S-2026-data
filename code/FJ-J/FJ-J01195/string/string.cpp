#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long a[N], n, ans, lst1, lst2;
char op[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> op[i];
	for (int l = 1, r = n; l < r;) {
		long long tmp = min(a[l], a[r]);
		a[l] -= tmp, a[r] -= tmp, ans += tmp * (op[l] != op[r]);
		if (!a[l]) l ++;
		if (!a[r]) r --;
	}
	cout << ans;
	return 0;
}

