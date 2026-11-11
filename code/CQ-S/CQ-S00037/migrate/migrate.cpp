#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int input() {
	int x;
	cin >> x;
	return x;
}
int a[2000005];
void f() {
	int ans = 0, n = input(), m = input();
	for (int i = 1; i <= n; i ++) a[i] = input();
	if (m - 2) {
		cout << 0 << endl;
		return ;
	}
	for (int i = 1; i <= n - m - 1; i ++) {
		if (a[i + m + 1] - a[i] == m + 1) ans ++;
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    int c = input(), T = input();
    while (T --) f();
	return 0;
}
//4 4
//1 3 4 6
