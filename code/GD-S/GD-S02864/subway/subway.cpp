#include<bits/stdc++.h>
using namespace std;
int a[501][501],t[501][501],w[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,x,y,sj=0;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		scanf("%d%d",&a[i][j],&t[i][j]);
	}
	for(int o=1;o<=q;o++)
	{
		scanf("%d%d",&x,&y);
		sj+=w[x]+w[y];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				if(a[i][j]==x||a[i][j]==y)
		j+=t[i][j];
		printf("%d\n",sj);
		sj=0;
	}
	return 0;
 } 
