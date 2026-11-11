#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],b[400400]={0},maxn=-1;
int  main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		if(i==n)
		{
			b[a[i]]=i;
		}
		if(a[i]<a[i+1])
		{
			b[a[i]]=i;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	 } 
	return 0;
 } 
