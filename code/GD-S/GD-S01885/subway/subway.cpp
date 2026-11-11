#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,n,m,d,q;
int w[N],k[1005],a[5][N],t[5][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[i][j],&t[i][j]);
	}
	if(n==1)
	{
		for(int i=1;i<=q;i++)
		{
			int x,y,ti=0;
			scanf("%d%d",&x,&y);
			for(int j=1;j<=k[1];j++)
			{
				if(a[1][j]==x||a[1][j]==y)
				{
					ti+=t[1][j];
				}
			}
			printf("%d\n",ti+w[x]+w[y]);
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			int x,y,ti=0;
			scanf("%d%d",&x,&y);
			for(int j=1;j<=k[1];j++)
			{
				for(int l=1;l<=k[2];l++)
				{
					if(a[1][j]==a[2][l])
					{
						ti=t[1][j]+t[2][l];
						printf("%d\n",ti);
						break;
					}
				}
				if(ti) break;
			}
		} 
	}
	return 0;
}

