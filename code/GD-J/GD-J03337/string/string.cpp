#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
char c[N];
void change(int &x, int &y) {
	if (a[x] == a[y]) x++, y--;
	else if (a[x] < a[y]) a[y] -= a[x], x++;
	else a[x] -= a[y], y--;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int ans = 0;
	for (int i = 1, j = n; i < j; ) {
		if (c[i] == c[j]) change(i, j);
		else {
			ans += min(a[i], a[j]);
			change(i, j);
		}
	}
	cout << ans << '\n';
	return 0;
} 
