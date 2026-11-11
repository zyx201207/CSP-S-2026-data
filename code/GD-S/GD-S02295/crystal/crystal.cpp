#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],sum[500005];
int bigans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int l = 1,r = i,mid,ans;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m)
			{
				r = mid - 1;
				ans = mid;
			}
			else
				l = mid + 1;
		}
		bigans = max(bigans,i - ans + 1);
		//cout << ans << endl;
	}
	cout << bigans;
}
