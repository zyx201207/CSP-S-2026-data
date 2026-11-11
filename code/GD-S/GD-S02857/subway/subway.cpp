#include<bits/stdc++.h>
using namespace std;
const int N=500010,Q=100010;
int c,n,m,d,q;
int w[N],k[N],a[1000][1000],t[1000][1000];//w[M]地铁口到站厅 K[I]第i条线路经过k个站 ai,j 表示第 i 条线路经过的第 j 个地铁站，
//，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
int x[Q],y[Q];//x起点y终点 
int dp[1000][1000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++)scanf("%d",&w[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++)scanf("%d%d",&a[i][j],&t[i][j]);
	}
	for(int i=0;i<m;i++)dp[i][i]=w[i];
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		for(int j=x[i];j<y[i];j++)
		{
			for(int k=j+1;k<y[i];k++)
			{
//				if()
				dp[j][k]=min(dp[j][k],dp[j][k-1]-w[k-1]-t[0][k-1]+t[0][k]+w[k]);
			}
		}
		printf("%d\n",dp[x[i]][y[i]]);
	}
	return 0;
}
