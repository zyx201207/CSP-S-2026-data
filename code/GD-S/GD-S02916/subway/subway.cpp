#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,q;
int W[N],kk[N],rnk[N][N],a[N][N],t[N][N],dis[N][N],com[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	memset(dis,0x3f,sizeof dis);
	memset(com,-1,sizeof com);
	for(int i=1;i<=n;i++)
	{
		cin>>kk[i];
		for(int j=1;j<=kk[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			rnk[a[i][j]][i]=j;
		}
		for(int j=1;j<=kk[i];j++)
			for(int k=1;k<=kk[i];k++)
			{
				int u=a[i][j],v=a[i][k];
				dis[u][v]=dis[v][u]=0;
				com[u][v]=com[v][u]=i;
			}	

		
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			if(i==k||com[i][k]==-1) continue;
			for(int j=1;j<=m;j++)
			{
				if(i==j||j==k||com[k][j]==-1) continue;
				if(com[i][j]==com[k][j]) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]+2*t[com[i][k]][rnk[i][com[i][k]]]+2*t[com[k][j]][rnk[j][com[k][j]]]);
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=m;j++)
			{
				if(i==j||j==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+2*W[x]+2*W[y]<<'\n';
	}
}
