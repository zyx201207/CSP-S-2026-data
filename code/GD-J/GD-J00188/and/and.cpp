#include <bits/stdc++.h>
using namespace std;
int m, n;
long long a[200001], ans;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	ans = a[m];
	for (int i = m - 1; i > m - n; i--) ans &= a[i];
	cout << ans;
	return 0;
}
