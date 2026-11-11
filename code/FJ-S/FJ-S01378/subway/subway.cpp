#include<bits/stdc++.h>
using namespace std;
//#define long long long long
const long long N=509,M=5e5+9,INF=1e17;
//long long x;
long long c,n,m,d,q,dis[N][N],w[M],xv[M][22],ge[M];
int t[N][M];
long long Min(long long a,long long b)
{
	if(a<b)return a;
	return b;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long ha,i=1;i<=n;i++)
	{
		cin>>ha;
		for(long long x,j=1;j<=ha;j++)
		{
			cin>>x;cin>>t[i][x];
			xv[x][++ge[x]]=i;
		}
	}
//	for(int i=1;i<=n;++)
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
		{
			if(i!=j)
				dis[i][j]=INF;
		}
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=ge[i];j++)
			for(long long k=1;k<=ge[i];k++)
			{
				long long x=xv[i][j],y=xv[i][k];
				if(x==y)continue;
				dis[x][y]=Min(dis[x][y],(long long)t[x][i]+(long long)t[y][i]);
//				cout<<x<<' '<<y<<' '<<dis[x][y]<<"??\n";
			}
	}
	for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)dis[i][j]=Min(dis[i][k]+dis[k][j],dis[i][j]);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)cout<<"qi:"<<i<<" "<<"zh:"<<j<<" dis:"<<dis[i][j]<<'\n';
//		cout<<"____\n";
//	}
	for(long long x,y,ci=1;ci<=q;ci++)
	{
		long long ans=INF;
		cin>>x>>y;
		for(long long i=1;i<=ge[x];i++)
		{
			for(long long j=1;j<=ge[y];j++)
			{
				long long qi=xv[x][i],zh=xv[y][j];
//				if(qi==zh)cout<<dis[qi][zh]<<"$$$\n";
				if(dis[qi][zh]!=INF)ans=Min(ans,w[x]+w[y]+t[qi][x]+t[zh][y]+dis[qi][zh]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
