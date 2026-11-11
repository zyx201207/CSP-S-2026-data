#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=-1,t;
	cin>>n>>m;
	long long ns[n];
	for(long long i=0;i<n;i++)
	{
		cin>>ns[i];
	}
	if(m==1)
	{
		for(long long i=0;i<n-1;i++)
		{
			maxn=max(ns[i],ns[i+1])>maxn?max(ns[i],ns[i+1]):maxn;
		}
	}
	else if(m==2)
	{
		for(long long i=0;i<n;i++)
		{
			for(long long j=0;j<n;j++)
			{
				if(j==i)
				{
					continue;
				}
				else
				{
					t=ns[i]&ns[j];
					
					maxn=t>maxn?t:maxn;
				}
			}
		}
	}
	else if(m==n)
	{
		maxn=ns[0];
		for(long long i=1;i<=n;i++)
		{
			maxn=maxn&ns[i];
		}
	}
	cout<<maxn;
	return 0;
}
