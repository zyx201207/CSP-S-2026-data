#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],sum;
long long q(long long x,long long y)
{
	int z=1;
	long long s=0;
	while(x>0 && y>0)
	{
		if(x%2==y%2)
	        s=s+x%2*z;
	    x/=2;
	    y/=2;
	    z*=2;
	}
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		sum=q(a[1],a[2]);
		for(int i=3;i<=n;i++)
		{
			sum=q(a[i],sum);
		}
	}
	else if(m==1)
	    for(int i=1;i<=n;i++)
	        sum=max(sum,a[i]);
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++)
		        sum=max(q(a[i],a[j]),sum);
	}
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++)
		        for(int k=j+1;k<=n;k++)
				{
		        	int t=q(a[i],a[j]);
		        	sum=max(q(a[k],t),sum);
				}
    }
	else if(m==4)
	{
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++)
		        for(int k=j+1;k<=n;k++)
		            for(int l=k+1;l<=n;l++)
					{
			        	int t=q(a[i],a[j]);
			        	t=q(t,a[k]);
			        	sum=max(q(a[l],t),sum);
					}
		        
	}
	cout<<sum;
	return 0;
}
