#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2;
ll dis[N*3+5][N*3+5];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m*(n+2);i++)
	{
		for(int j=1;j<=m*(n+2);j++)
		{
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		ll w;
		scanf("%lld",&w);
		dis[i][m+i]=dis[m+i][i]=w;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		int la=0;
		for(int j=1;j<=k;j++)
		{
			int a;
			ll t;
			scanf("%d%lld",&a,&t);
			if(j>1)
			{
				dis[la+(i+1)*m][a+(i+1)*m]=0;
			}
			dis[m+a][a+(i+1)*m]=dis[a+(i+1)*m][m+a]=t;
			la=a;
		}
	}
	for(int k=1;k<=m*(n+2);k++)
	{
		for(int i=1;i<=m*(n+2);i++)
		{
			for(int j=1;j<=m*(n+2);j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",dis[x][y]);
		}
	}
	return 0;
}
