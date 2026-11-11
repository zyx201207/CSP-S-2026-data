#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][450005],t[505][450005];
int k[505];
long long ans;
void dfs(int p,int s,int y,long long time)
{
	for (int j=s+1;j<=k[p];j++)
	{
		if (a[p][j]==y)
		{
			ans=min(ans,time+t[p][y]);
			return ;
		}
		for (int i1=1;i1<=n;i1++)
		{
			if (i1==p) continue;
			for (int j1=1;j1<=k[i1];j1++)
			{
				if (a[p][j]==a[i1][j1])
				{	
					dfs(i1,j1,y,time+t[p][a[p][j]]+t[i1][a[p][j]]);
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++)
		{
			scanf("%d",&a[i][j]);
			scanf("%d",&t[i][a[i][j]]);
		}
	}
	while (q>0)
	{
		ans=INT_MAX;
		int x,y;
		scanf("%d%d",&x,&y);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=k[i];j++)
			{
				if (a[i][j]==x)
				{
					dfs(i,j,y,t[i][a[i][j]]);
				}
			}
		}
		cout <<ans+w[x]+w[y] <<endl;
		q--;
	}
	return 0;
}
