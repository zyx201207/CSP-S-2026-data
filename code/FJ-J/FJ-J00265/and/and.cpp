#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
inline bool ispow(int x)
{
	int y = log2(x);
	return pow(2, y) == x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n), reverse(a + 1, a + 1 + n);
	int ans = -1;
	for (int i = 1; i <= m; i++)
	if (ispow(a[i]) || (i < m && ispow(a[i] + a[i + 1] + 1))) { m++; continue; } else { if (ans == -1) ans = a[i]; else ans &= a[i]; }
	cout << ans << '\n';
	return 0;
}
