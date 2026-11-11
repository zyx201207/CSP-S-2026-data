#include <iostream>
#include <algorithm>
#define intt long long
using namespace std;
const intt N = 5e5 + 10;
intt n, m, cnt, ans = 1, a[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal3.in", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (intt i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (intt i = 2, j = 1; i <= n; i++)
	{
		cnt += 1ll * (i - j) * (a[i] - a[i - 1]);
		while (cnt > m) cnt -= a[i] - a[j++];
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
