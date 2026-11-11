#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],st[500005],f[500005];
dfs(int x)
{
	if(st[x]==x+1)
	{
		return x+1;
	}
	st[x]=dfs(st[x]-1);
	return st[x];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			st[j]=j+1;
			if(!f[a[j]])
			{
				f[a[j]]=j;
			}
			else
			{
				st[f[a[j]]]=j+1;
				f[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			dfs(j);
		 } 
		for(int j=i;j<=n;j=st[j])
		{
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
