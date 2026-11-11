#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 501;
const int M = 5e5 + 1;
const int D = 21;
int c,n,m,d,q,k[N],l,r;
ll foot[M],subls[N][N<<1][2],dis[1001][1001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&foot[i]);
		dis[i][i]=0;
	}	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&subls[i][j][0],&subls[i][j][1]);
		for(int j=1;j<=k[i];j++)
			for(int l=j+1;l<=k[i];l++)
				dis[subls[i][j][0]][subls[i][l][0]]=dis[subls[i][l][0]][subls[i][j][0]]=min(subls[i][l][1]+subls[i][j][1],dis[subls[i][l][0]][subls[i][j][0]]);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int l=1;l<=m;l++)
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",l==r?0:(foot[l]+foot[r]+dis[l][r]));
	}
	return 0;	
} 
