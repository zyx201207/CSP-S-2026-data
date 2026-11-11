#include<bits/stdc++.h>
using namespace std;
long long a[200000],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			int x=0;
			for(int j=i+1;j<=n;j++)
			{
				x=a[i]&a[j];
				if(ans<x)
				{
					ans=x;
				}
			}
		}
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int x=0;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					x=a[i]&a[j]&a[k];
					if(ans<x)
					{
						ans=x;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
