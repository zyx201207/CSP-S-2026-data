#include<cstdio>
int w[500010];
int sub[60][310],k[60];
int t[60][310];
long long dt[310][310];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	if(c<=6)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++)scanf("%d%d",&sub[i][j],&t[i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j1=1;j1<=k[i];j1++)
			{
				for(int j2=1;j2<=k[i];j2++)
				{
					if(j1==j2)continue;
					int s1=sub[i][j1],s2=sub[i][j2];
					if(dt[s1][s2]==0)dt[s1][s2]=t[i][j1]+t[i][j2];
					else dt[s1][s2]=(dt[s1][s2]<t[i][j1]+t[i][j2]?dt[s1][s2]:t[i][j1]+t[i][j2]);
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=m;k++)
				{
					if(dt[i][k]==0||dt[k][j]==0)continue;
					if(dt[i][j]!=0)dt[i][j]=(dt[i][j]<dt[i][k]+dt[k][j]?dt[i][j]:dt[i][k]+dt[k][j]);
					else dt[i][j]=dt[i][k]+dt[k][j];
				}
			}
		}
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",dt[x][y]+w[x]+w[y]);
		}
		return 0;
	}
	return 0;
}
