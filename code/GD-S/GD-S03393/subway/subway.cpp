#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[510][1020],w[1100],k[700];
long long int dp[1020][1020],t[510][1020],tt;
int x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&a[i][j],&tt);
			t[i][a[i][j]]=tt;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dp[i][j]=10000000000;
	for(int z=1;z<=n;z++)
	{
		for(int i=1;i<k[z];i++)
		{
			for(int j=i+1;j<=k[z];j++)
			{
				dp[a[z][i]][a[z][j]]=min(dp[a[z][i]][a[z][j]],t[z][a[z][i]]+t[z][a[z][j]]);
				dp[a[z][j]][a[z][i]]=dp[a[z][i]][a[z][j]];
			}
		}
	}
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++)
		{
			for(int z=1;z<=m;z++)
			{
				if(z==i||z==j)continue;
				dp[i][j]=min(dp[i][j],dp[i][z]+dp[z][j]);
			}
		}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",dp[x][y]+w[x]+w[y]);
	}
	return 0;
 } 
