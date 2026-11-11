#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],lst[300010],f[500010],ans[300010],l[300010],vis[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>0;i--)
	{
		if(lst[a[i]])
		{
			l[i]=lst[a[i]];
		}
		lst[a[i]]=i;
	}
	for(int i=n;i>0;i--)
	{
		if(vis[a[i]]==0)
		{
			f[i]=a[i];
			vis[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(l[j])
			{
				j=l[j]-1;
			}
			else
			{
				if(f[j])
				{
					ans[f[j]]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
