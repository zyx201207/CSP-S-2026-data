#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[300005];
int vis[300005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) ok=0;
	}
	if(ok)
	{
		for(int i=1;i<=n;i++) b[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<b[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]]) vis[a[j]]=j;
			else
			{
				for(int k=1;k<=m;k++)
				{
					if(vis[k]>vis[a[j]]&&vis[k]<j) vis[k]=0;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(vis[j]) b[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
