#include <bits/stdc++.h>
using namespace std;
long long n,m,a[300000],sum;
int b[1000],c[1000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long mm=a[n],zhi=1;
	while (mm>=1)
	{
		b[zhi]=mm%2;
		mm/=2;
		zhi++;
	}
	for (int i=n-1;i>n-m;i--)
	{
		long long nn=a[i],zhizhen=1;
		while (nn>=1)
		{
			c[zhizhen]=nn%2;
			nn/=2;
			zhizhen++;
		}
		if (zhizhen>zhi)
		{
			zhi=zhizhen;
		}
		for (int l=1;l<=zhi;l++)
		{
			if (b[l]==1&&c[l]==1)
			{
				b[l]=1;
				c[l]=0;
			}
			else
			{
				b[l]=0;
				c[l]=0;
			}
		}
	}
	for (int i=zhi-1;i>=1;i--)
	{
		sum+=b[i]*pow(2,i-1);
	}
	if (sum==0)
	{
		cout << a[n-m+1];
	}
	else
	{
		cout << sum;
	}
	return 0;
}
