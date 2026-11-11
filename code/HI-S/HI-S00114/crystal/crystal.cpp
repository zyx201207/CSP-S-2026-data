#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,j;
	long long m,ls,d=0;
	int a[500000];
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>ls;
		if(i==0)
		{
			d=ls;
		}
		if(i==1)
		{
			d=abs(ls-d);
		}
		ls=ls%2147483647;
		a[i]=ls;
	}
	for(long long i=1;i<=m;ls=0)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1)
			{
				break;
			}
			if(a[j]!=a[j+1] && (d+j*d)<=(m-i+1))
			{
				for(long long k=0;k<=j;k++)
				{
					ls=a[k]+d;
					if(ls>2147483647)
					{
						ls=ls%2147483647;
					}
					a[k]=ls;
					i+=d;
					if(i>m)
					{
						break;
					}
					
				}
				break;
			}
			if(i>m)
			{
				break;
			}
		}
		if(j==n-1)
		{
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
		{
			ans++;
			break;
		}
		if(a[i]==a[i+1])
		{
			ans++;
		}
		else
		{
			ans++;
			break;
		}
	}
	cout<<ans;
	return 0;
}
