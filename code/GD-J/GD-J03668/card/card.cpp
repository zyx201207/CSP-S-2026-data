#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[500005],ans[500005];
int s[500005],top;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				vis[j]=0;
			for(int j=1;j<=top;j++)
				s[j]=0;
			top=0;
			for(int j=i;j<=n;j++)
			{
				if(vis[a[j]]==0)
				{
					s[++top]=a[j];
					vis[a[j]]=top;
				}
				else
				{
					for(int k=top;k>=vis[a[j]];k--)
					{
						s[k]=0;
					}
					top=vis[a[j]]-1;
					s[++top]=a[j];
				}
			}
			for(int j=1;j<=top;j++)
			{
				ans[s[j]]++;
			}
		}	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int x=0;
			for(int j=i;j<=n;j++)
			{
				if(j==i)
				{
					x=a[j];
					continue;
				}
				if(a[j]!=x)
				{
					ans[x]++;
					x=a[j];
				}
			}
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
