#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],ans=-1;
int f[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=30;i>=0;i--)
	{
		int num=0;
		for(int j=1;j<=n;j++)
		{
			if(f[j]==0)
			{
				if((a[j] & (1<<i))!=0)
				{
					num++;
				}
				
			}
		}
		if(num>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[j]==0)
				{
					if((a[j] & (1<<i))==0)
					{
						f[j]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			if(ans==-1)
			{
				ans=a[i];
			}
			else ans=ans & a[i];
		}
	}
	cout<<ans;
}
