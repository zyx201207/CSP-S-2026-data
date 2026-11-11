#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b,c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)b=1;
	}
	if(!b)
	{
		long long sum=n;
		for(int i=n-1;i>=1;i--)
		{
			if(m-(n-i)>=0)
			{
				m-=(n-i);
				sum+=n;
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		c[i]=a[i+1]-a[i];
	}
	sort(c+1,c+n);
	if(c[1]==c[n-1])
	{
		sort(a+1,a+n+1);
		long long sum=a[n];
		for(int i=n-1;i>=1;i--)
		{
			if(m-(a[n]-a[i])>=0)
			{
				m-=(a[n]-a[i]);
				sum+=a[n];
			}
		}
		cout<<sum;
		return 0;
	}
	long long mm=m,cnt=0,sum=0;
	for(int i=n-1;i>1;i--)
	{
		mm=m,sum=1;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=mm)
			{
				mm-=(a[i]-a[j]);
				sum++;
			}
		}
		cnt=max(cnt,sum);
	}
	cout<<cnt;
	return 0;
}