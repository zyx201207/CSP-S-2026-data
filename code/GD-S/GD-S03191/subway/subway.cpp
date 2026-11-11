#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3010;
int m,n,C,D,q,c[N],p[N];
ll d[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&q);
	for(int i=1;i<=m;i++) scanf("%d",&c[i]);
	for(int i=1;i<=m+n;i++)
		for(int j=i+1;j<=m+n;j++)
			if(i!=j) d[i][j]=d[j][i]=1e18;
	for(int i=1,k,a,t;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&a,&t);
			p[j]=a;
			d[a][m+i]=d[m+i][a]=t;
		}
		for(int I=1;I<=k;I++)
			for(int J=1;J<=k;J++) d[p[I]][p[J]]=min(d[p[I]][p[J]],d[p[I]][m+i]+d[m+i][p[J]]);
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				 d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",d[x][y]+c[x]+c[y]);
	}
	return 0;
}
//32~44pts
