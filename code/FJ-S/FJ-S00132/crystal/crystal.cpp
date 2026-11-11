#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[500005], cnt[500005], d[500005], ans = -1; 
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (d[i] + a[i] - a[j] <= m)
			{
				d[i] += a[i] - a[j];
				cnt[i]++;
			}
		}
	} 
	for (int i = 1; i <= n; i++)
		ans = max(ans, cnt[i]);
	cout << ans;
	return 0;
}
