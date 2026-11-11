#include<bits/stdc++.h>
using namespace std;
//D盘 
long long n,m;
long long a[500005];
long long b[500005];
long long dp[500005];
//dp[m]  表示以 m 为参照时前面数的改变量 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
//	cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
//    	cin >> a[i];
	}
	bool f = 0;
	for (int i=2;i<=n;i++)
	{
		if (a[i]!=i)
		{
			f = 1;
			break;
		}
	}
	if (f == 0)
	{
		long long sum1 = 0;
		for (int i=1;i<=n;i++)
		{
			sum1 += i;
			if (sum1 > m)
			{
				cout << sum1 - 1;
				break;
			}
		}
		return 0;
	}
	else
	{
		sort(a+1,a+1+n);
		for (int i=2;i<=n;i++)
		{
			b[i] = a[i]-a[i-1];
		}
		dp[1] = 0;
		for (int i=2;i<=n;i++)
		{
			long long sum = 1;
			sum = b[i]*(i-1);
			if (dp[i-1]+sum > m)
			{
				m =i-1;
				break;
			}
			else  dp[i] =  dp[i-1] + sum;
		}
//		int l = 1,r = n,mid=0;
//		while (l<=r)
//		{
//			mid = (l+r)>>1;
//			if (dp[mid]>m)  r = mid - 1;
//			else  l = mid + 1;
//		}
		printf("%lld",m);
//		cout << r;
	}
    return 0;
}

