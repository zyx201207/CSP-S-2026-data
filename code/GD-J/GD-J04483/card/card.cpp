#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[500005],ans[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(c,1,sizeof(c));
		for(int j=i;j<=n;j++)
		{
			if(c[j]==0)
				continue;
			if(vis[a[j]])
			{
				for(int k=vis[a[j]];k<=j-1;k++)
				{
					vis[a[k]]=0;
					c[k]=0;
				}
				vis[a[j]]=j;
			}
			else vis[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			if(c[j]==0) continue;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}
