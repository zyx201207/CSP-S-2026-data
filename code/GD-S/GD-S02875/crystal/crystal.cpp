#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], pre[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	pre[0] = 0;
	int ans = 1;
	for(int i=1;i<=n;i++)
	{
		pre[i] = pre[i - 1] + a[i];
		int l = 0, r = i;
		while(r - l > 1)
		{
			int mid = ((l + r) >> 1);
			if(pre[i] - pre[mid - 1] + mid * a[i] >= (i + 1) * a[i] - m)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans << endl;
	return 0;
}
