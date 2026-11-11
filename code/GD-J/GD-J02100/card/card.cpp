#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
long long b[500005];
long long n,m;
int main()
{
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>500)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				sum[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			
			if(b[a[j]])
			{
				for(int x=b[a[j]];x<=j;x++)
				{
					b[a[x]]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			
			if(b[a[j]])
			{
				sum[a[j]]++;
			}
			b[a[j]]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
 } 
