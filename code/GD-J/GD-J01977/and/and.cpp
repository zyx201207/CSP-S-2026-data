#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1,a[2000006];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
		for(int i=1;i<=n;i++)
			ans=max(a[i],ans);
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
	}
	else if(m==n-1)
	{
		for(int z=1;z<=n;z++)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==z)continue;
				for(int j=i+1;j<=n;j++)
				{
					if(j==z)continue;
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
	}
	cout<<ans;
} 
