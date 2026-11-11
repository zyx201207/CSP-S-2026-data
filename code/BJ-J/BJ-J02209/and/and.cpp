#include <bits/stdc++.h>
using namespace std;
int a[50000];
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
	if(m==1)
	{
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		int maxx=0;//0
		for(int i=1;i<=n-1;i++)//1     2
		{
			for(int j=i+1;j<=n;j++)//2   3  4 
			{
				int x=a[i]&a[j];//3&15    3&12   3&12
				maxx=max(maxx,x);//3   3   3
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==3)
	{
		int maxx=0;
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					int x=a[i]&a[j]&a[z];
					maxx=max(x,maxx);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==4)
	{
		int maxx=0;
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+1;j<=n-2;j++)
			{
				for(int z=j+1;z<=n-1;z++)
				{
					for(int k=z+1;k<=n;k++)
					{
						int x=a[i]&a[j]&a[z]&a[k];
						maxx=max(maxx,x);
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==5)
	{
		int maxx=0;
		for(int i=1;i<=n-3-1;i++)
		{
			for(int j=i+1;j<=n-2-1;j++)
			{
				for(int z=j+1;z<=n-1-1;z++)
				{
					for(int k=z+1;k<=n-1;k++)
					{
						for(int o=k+1;o<=n;o++)
						{
							int x=a[i]&a[j]&a[z]&a[k]&a[o];
							maxx=max(maxx,x);
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
