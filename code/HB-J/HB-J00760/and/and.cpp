#include<iostream>
#include<cmath>
using namespace std;
long long n,a[300000],maxn,d,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<n;i++)
		{
			d=a[i];
			maxn=max(maxn,d);
		}
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				d=a[i]&a[j];
				maxn=max(maxn,d);
			}
		}
	}
	if(m==3)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					d=a[i]&a[j]&a[k];
					maxn=max(maxn,d);
				}
			}
		}
	}
	if(m==3)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					d=a[i]&a[j]&a[k];
					maxn=max(maxn,d);
				}
			}
		}
	}
	cout<<maxn;
}
