#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[500010], sum[500010];
int ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i;
		while (l < r)
		{
			int mid = l + r >> 1, ae = (i - mid) * a[i], be = sum[mid - 1] - sum[i - 1];
			long long ans = 0, ans1 = 0;
			for (int j = mid; j < i; j++)ans1 += a[j];
			if (ae - ans1 <= m)r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}
