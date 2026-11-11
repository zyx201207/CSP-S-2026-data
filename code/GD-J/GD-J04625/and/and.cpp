#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1100100];
int  main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else if(m==n)
	{
		long long ans=a[1];
		for(long long i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		long long man=-1;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				long long num=a[i]&a[j];
				man=max(man,num);
			}
		}
		cout<<man;
		return 0;
	}
	return 0;
 } 
