#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==1)
	{
		int maxa=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>maxa)
			maxa=a[i];
		}
		cout<<maxa;
		return 0;
	}
	if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
		sum&=a[i];
		cout<<sum;
		return 0;
	}
	if(m==2)
	{
		int amax=0,sum;
		for(int i=1;i<=n;i++)
		{
			sum=a[i];
			for(int j=i+1;j<=n;j++)
			{
				sum&=a[j];
				amax=max(amax,sum);
			}
		}
		cout<<amax;
		return 0;
	}
	if(m==n-1)
	{
		int amax=0,sum=a[1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j&&i==1)
				{
					sum=a[2];
					j++;
					continue;
				}
				if(i==j)
				continue; 
				sum&=a[j];
			}
		amax=max(amax,sum);
		}
		cout<<amax;
	}
	return 0;
}
