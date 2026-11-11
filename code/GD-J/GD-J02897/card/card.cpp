#include<bits/stdc++.h>
using namespace std;
int a[1001000],vis[1001000],cnt[1001000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i]=a[i]; 
	}
	for(int k=1;k<=n;k++)
	{
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(vis[i]==vis[j])
				{
					for(int p=i;p<=j-1;p++)
					{
						vis[p]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cnt[vis[i]]++;
		}
		
		a[k]=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=a[i];
		} 
	}
	for(int i=1;i<=m;i++)
	{
		if(cnt[i]!=0)
		{
			cout<<cnt[i]<<" ";
		}
	}
	return 0;
}
