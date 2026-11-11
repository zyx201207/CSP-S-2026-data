#include<bits/stdc++.h>
namespace My
{
	using namespace std;
	typedef long long ll;
	const int N=505;
	const int M=500005;
	int c,n,m,d,q;
	int sum[M],a[M][22];
	ll dis[N][N],w[M],l[M][22];
	int main()
	{
//		system("fc subway.out subway7.ans");return 0;
//		freopen("subway7.in","r",stdin);
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(1ll<<45);
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int p=1;p<=n;p++)
		{
			int k;
			cin>>k;
			for(int r=1;r<=k;r++)
			{
				int i;
				cin>>i;
				sum[i]++;
				int j=sum[i];
				a[i][j]=p;
				cin>>l[i][j];
				for(int x=1;x<j;x++)
				{
					dis[a[i][j]][a[i][x]]=dis[a[i][x]][a[i][j]]=min(dis[a[i][j]][a[i][x]],l[i][j]+l[i][x]);
				}
			}
		}
		for(int x=1;x<=n;x++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][x]+dis[x][j]);
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			ll ans=(1ll<<45);
			for(int i=1;i<=sum[x];i++)
				for(int j=1;j<=sum[y];j++)
					ans=min(ans,dis[a[x][i]][a[y][j]]+w[x]+w[y]+l[x][i]+l[y][j]);
			cout<<ans<<"\n";
		}
		return 0;
	}
}
int main()
{
	return My::main();
}
