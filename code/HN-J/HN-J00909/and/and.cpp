#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N], idx, ans, nw[N];
int check(int x) {
	int num = 0;
	idx = 0;
	for (int i = 1; i <= n; i ++)
		num += (a[i] >> x) & 1;
	if (num < m)
		return 0;
	for (int i = 1; i <= n; i ++)
		if ((a[i] >> x) & 1)
			nw[++ idx] = a[i];
	n = idx;
	for (int i = 1; i <= n; i ++)
		a[i] = nw[i];
	return 1;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 30; i >= 0; i --)
		ans += check(i) * (1 << i);
	cout << ans;
	return 0;
}
/*
\bx xyz 出了这道题的加强板 
*/
