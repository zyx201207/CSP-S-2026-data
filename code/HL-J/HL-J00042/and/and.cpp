#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[1000010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long maxn=0;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		if(maxn<a[i])maxn=a[i];
	}
	else
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(maxn<(a[i]&a[j]))maxn=a[i]&a[j];
			} 
		} 
	
	}
	else
	{
		
	if(m==n)
	{
		int x=1;
		for(int i=1;i<=n;i++)
		if(i==1)x=a[i];
		else
		x&=a[i];
		maxn=x;
	}
	else
	if(m==n-1)
	{
		int x=1;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			x=a[i];
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(i==1&&j==2)x=a[j];
				else
				x&=a[j];
			}
			if(maxn<x)maxn=x;
		}
	}
	}
	
	cout<<maxn; 
	return 0;
}
