#include<bits/stdc++.h>
using namespace std;
int n;
long long m,sum=0;
long long v[555555];
long long c[555555];
long long a=0;
long long fun(long long p,long long x,long long y)
{
	long long ans=0;
	for(long long i=p;i<=x;i++)
	{
		sum=0;
		for(long long j=1;j<=i;j++)
		{
			sum+=c[i];
			if(sum==y&&j==i)
			{
				ans=i+1;
				long long cnt=0;
				for(long long k=i+1;k<x;k++)
				{
					if(c[k]==0)
					{
						cnt++;
					}
				}
				ans+=cnt;
				return ans;
			}
			if((sum==y&&j!=i)||sum>y)
			{
				ans=i;
				long long cnt=0;
				for(long long k=i+1;k<x;k++)
				{
					if(c[k]==0)
					{
						cnt++;
					}
				}
				ans+=cnt;
				return ans;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>v[i];
	}	
	sort(v+1,v+1+n);
	c[n]=0;
	for(long long i=1;i<n;i++)
	{
		c[i]=v[i+1]-v[i];
	}
	for(long long i=1;i<=n;i++)
	{
		int num=fun(i,n,m);
		if(a<=num)
		{
			a=num;
		}
	}
	cout<<a<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
