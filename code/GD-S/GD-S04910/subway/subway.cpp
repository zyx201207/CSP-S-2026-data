#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXM=15007;
int w[MAXM];
long long adj[MAXM][MAXM];
int main()
{
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m+n;i++)
	{
		for(int j=1;j<=m+n;j++)
		{
			adj[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int zhan,time;
			scanf("%d%d",&zhan,&time);
			adj[m+i][zhan]=time;
			adj[zhan][m+i]=time;
		}
	}
	for(int k_=m+1;k_<=m+n;k_++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				adj[i][j]=min(adj[i][j],adj[i][k_]+adj[k_][j]);
			}
		}
	}
	for(int k_=1;k_<=m;k_++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				adj[i][j]=min(adj[i][j],adj[i][k_]+adj[k_][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int le,ri;
		scanf("%d%d",&le,&ri);
		printf("%lld\n",adj[le][ri]+w[le]+w[ri]);
	}
	return 0;
}
