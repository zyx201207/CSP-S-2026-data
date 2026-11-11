#include<bits/stdc++.h>
using namespace std;
long long awy(long long a,long long b)
{
	long long js=0;
	while(1==1)
	{
		int aa,bb;
		if((aa==1)||(bb==1))
		{
			break;
		}
		if((aa%2)==(bb%2))
		{
			js++;
		}
		aa=aa/2;
		bb=bb/2;
	}
	return js;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,z_max=0,aaa[20005];
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		long long s;
		cin>>s;
		aaa[i]=s;
	}
	if(n==m)
	{
		for(long long i=1;i<n;i++)
		{
			z_max+=awy(aaa[i],aaa[i+1]);
		}
		cout<<z_max;
		return 0;
	}
	for(long long i=1;i<n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			if(aaa[i]==aaa[j])
			{
				if(aaa[i]>z_max)
				{
					z_max=aaa[i];
				}
			}
		}
	}
	if(z_max!=0)
	{
		cout<<z_max;
		return 0;
	}
	if(m==2)
	{
		for(long long i=1;i<n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				long long sz=awy(aaa[i],aaa[j]);
				if(sz>z_max)
				{
					z_max=sz;
				}
			}
		}
	}
	cout<<z_max;
	return 0;
}
