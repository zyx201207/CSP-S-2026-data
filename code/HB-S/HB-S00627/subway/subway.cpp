//R.I.P

#include <bits/stdc++.h>
using namespace std;

const int MAXN=501,MAXM=5e3+10;
int c,n,m,d,q;
int a[MAXN][MAXM],t[MAXN][MAXM],w[MAXM];
int tu[MAXM][MAXM];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	memset(tu,0x3f3f3f3f,sizeof(tu));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int tot;
		scanf("%d",&tot);
		for(int j=1;j<=tot;j++)
			scanf("%d%d",&a[i][j],&t[i][j]);
		for(int j=1;j<tot;j++)
		{
			for(int k=j+1;k<=tot;k++)
			{
				tu[a[i][j]][a[i][k]]=t[i][j]+t[i][k];
				tu[a[i][k]][a[i][j]]=t[i][j]+t[i][k];
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",tu[x][y]+w[x]+w[y]);
	}
	return 0;
}