#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
long long ct[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];	
	for(long long t=1;t<=n;t++)
	{
		long long c[300001]={},l=1;
		c[l]=a[t];
		for(long long i=t+1;i<=n;i++)
		{
			long long k=-1;
			for(long long j=1;j<=l;j++)
			{
				if(c[j]==a[i])
				{
					k=j;
					break;
				}
			}
			if(k==-1) l++;
			else
			{
				for(int j=k;j<=l;j++)
					c[j]=0;
				l=k;
			}
			c[l]=a[i];
		}
		for(long long i=1;i<=l;i++)
			ct[c[i]]++;
	}
	for(long long i=1;i<=m;i++)
		cout<<ct[i]<<' ';
	return 0;	
}
