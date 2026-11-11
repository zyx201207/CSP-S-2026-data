#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],c[500001],sum[500001],k[500001],q[500001],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		c[i] = a[i]-a[i-1]; 
		if (c[i] != c[i-1]&&i != 1)
			flag = 0;
		sum[i] = sum[i-1]+c[i];
		k[i] = k[i-1]+c[i]*(i-1);
		q[i] = q[i-1]+sum[i];
	}
	if (flag)
	{
		int pos = 0;
		for (int i = 1;i <= n;i++)
		{
			if (k[i] >= m)
			{
				pos=i-1;
				if (m == k[i])
				{
					++pos;
				}
				break;
			}
		}
		if (pos < c[2])
			pos = 0;
		cout << pos;
		return 0;
	}
	for (int i = n;i >= 1;i--)
	{
		long long r = 0,ge = 1;
		for (int j = 1;j <= i;j++)
		{
			if(i-j+1<=ans)
				break;
			r = k[i] - (j-1)*sum[i] + q[j-1];
			if (m>=r)
			{
				ge = i-j+1;
				break;
			}
		}
		ans = max(ans,ge);
	}
	cout << ans;
	return 0;
}
