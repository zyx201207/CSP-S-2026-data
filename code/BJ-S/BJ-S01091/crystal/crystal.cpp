#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int las = 1, tot = 0, ans = 1;
	for(int i = 2; i <= n; i ++)
	{
		while(las < i && tot + (a[i] - a[i - 1]) * (i - las) > m)
		{
			tot -= a[i - 1] - a[las];
			las ++;
		}
		if(las <= i && tot + (a[i] - a[i - 1]) * (i - las) <= m)
		{
			tot += (a[i] - a[i - 1]) * (i - las);
			ans = max(ans, i - las + 1);
		}
	}
	cout << ans;
	return 0;
}
