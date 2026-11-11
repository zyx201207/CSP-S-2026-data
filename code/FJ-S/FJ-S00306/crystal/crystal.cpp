#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.txt", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long ans = -1, sum = 0, l = 1;
	for (long long r = 1; r <= n; r++)
	{
		while (l <= r && sum > m)
		{
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
		sum += (a[r + 1] - a[r]) * (r - l + 1);
	}
	cout << ans;
	return 0;
 }
