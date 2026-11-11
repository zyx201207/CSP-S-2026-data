#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m, sum, ans, a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1; r <= n; r++)
	{
		sum += (r - l) * (a[r] - a[r - 1]);
		while (sum > m)
			sum -= a[r] - a[l], l++;
		ans = max(ans, r - l + 1ll);
	}
	cout << ans << endl;
	return 0;
}