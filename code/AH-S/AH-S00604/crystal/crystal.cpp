#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define MAXN 500005
ll n, m, sum[MAXN], ans, a[MAXN];
bool cmp(ll x, ll y)
{
	return x > y;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		sum[i] += a[1] - a[i];
	}
	ll cnt = upper_bound(sum + 1, sum + n + 1, m) - sum - 1;
	ans = max(ans, cnt);
	for (int i = 2; i <= n; i++)
	{
		m += (a[i - 1] - a[i]);
		cnt = upper_bound(sum + 1, sum + n + 1, m) - sum - 1;
		ans = max(ans, cnt - i + 1);
	}
	cout << ans;
	//******hope ac!
	return 0;
}

