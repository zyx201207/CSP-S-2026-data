#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("and.in","f",stdin);
	freopen("and.out","w",stdout);
	int n,p;
	cin>>n>>p;
	int zhi=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	if(p==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				zhi=max(a[i]&a[j],zhi);	
			}
		}
		cout<<zhi;
	}
	if(p==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int x=j+1;x<=n;x++)
				{
					int s=a[i]&a[j];
					zhi=max(s&a[x],zhi);
				}	
			}
		}
		cout<<zhi;
	}
	if(p==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int x=j+1;x<=n;x++)
				{
					for(int d=x+1;d<=n;d++)
					{
						int s=a[i]&a[j];
						int f=s&a[x];
						zhi=max(zhi,f&a[d]);
					}
				}	
			}
		}
		cout<<zhi;
	}
	if(p==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int x=j+1;x<=n;x++)
				{
					for(int d=x+1;d<=n;d++)
					{
						for(int h=d+1;h<=n;h++)
						{
							int s=a[i]&a[j];
							int f=s&a[x];
							int q=f&a[d];
							zhi=max(zhi,q&a[h]);
						}
					}
				}	
			}
		}
		cout<<zhi;
	}		
	return 0;
}

