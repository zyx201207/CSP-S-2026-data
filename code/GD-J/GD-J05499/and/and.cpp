#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2)
	{
		maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long t=(a[i]&a[j]);
				maxx=max(maxx,t);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1)
	{
		maxx=-1;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				sum=a[2];
			}
			else
			{
				sum=a[1];
			}
			for(int j=1;j<=n;j++)
			{
				if(a[j]==a[i])
				{
					continue;
				} 
				sum&=a[j];
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n);
	sum=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
