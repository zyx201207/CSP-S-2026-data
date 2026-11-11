#include<cstdio>
#include<vector>
#define ll long long int 
using namespace std;
const int Infi=1e9;
const ll Infl=1e16;
const int N=5e2,M=5e5,D=20;
ll w[M+5];
ll ds[N+5][N+5];
int a[N+5][M+5];
vector<int> b[M+5];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
		for(int j=1;j<=n;j++)
		{
			a[j][i]=Infi;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			ds[i][j]=ds[j][i]=Infl;
		}
		int ln;
		scanf("%d",&ln);
		for(int j=1;j<=ln;j++)
		{
			int x;
			scanf("%d",&x);
			b[x].push_back(i);
			scanf("%d",&a[i][x]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int x:b[i])
		{
			for(int y:b[i])
			{
				ds[x][y]=min(ds[x][y],(ll)a[x][i]+a[y][i]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ll ans=Infl;
		for(int x:b[u])
		{
			for(int y:b[v])
			{
				ans=min(ans,a[x][u]+ds[x][y]+a[y][v]);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
