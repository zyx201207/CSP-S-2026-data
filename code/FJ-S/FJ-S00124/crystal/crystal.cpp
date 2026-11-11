#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int maxx = -1;
int a[500005];
int sum[500005];
signed main()
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
	for (int j = 1;j <= n;j++)
	{
		int l = 1,r = j,i;
		while (l <= r)
		{
			i = (l + r) / 2;
			if ((j - i + 1) * a[j] - (sum[j] - sum[i - 1]) <= m)
			{
				maxx = max(maxx,j - i + 1);
				r = i - 1;
			}
			else
			{
				l = i + 1;
			}
		}
	}
	cout << maxx;
	return 0;
}
