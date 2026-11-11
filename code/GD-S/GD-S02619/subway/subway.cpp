#include<bits/stdc++.h>
using namespace std;
long long w[1000005];
//long long tim[1005][1005];
struct node
{
	long long xian[105],xiantim[105];
	long long cnt;
}a[1000005];
long long dis[1005][1005],vis[1005][1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e15;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int n2;
		cin>>n2;
		for(int j=1;j<=n2;j++)
		{
			long long x,t;
			cin>>x>>t;
			for(int k=1;k<=a[x].cnt;k++)
			{
				dis[a[x].xian[k]][i]=min(dis[a[x].xian[k]][i],a[x].xiantim[k]+t);//i>a[x].xian[k]
			}
			a[x].cnt++;
			a[x].xian[a[x].cnt]=i;
			a[x].xiantim[a[x].cnt]=t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>j)
			{
				dis[i][j]=dis[j][i];
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int ii=1;ii<=q;ii++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e15;
		for(int i=1;i<=a[x].cnt;i++)
		{
			for(int j=1;j<=a[y].cnt;j++)
			{
				ans=min(ans,dis[a[x].xian[i]][a[y].xian[j]]+a[x].xiantim[i]+a[y].xiantim[j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
//small trick-> maxk=2 in all samples
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
