#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=505;
const int M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q,w[M],k;
int a[M][25],t[M][25],tp[M];
ll g[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int A,T;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>A>>T;
			tp[A]++;
			a[A][tp[A]]=i;
			t[A][tp[A]]=T;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=inf;
	for(int i=1;i<=n;i++)g[i][i]=0;
	int u,v;
	for(int i=1;i<=m;i++)
	{
		for(int x=1;x<=tp[i];x++)
		{
			u=a[i][x];
			for(int y=x+1;y<=tp[i];y++)
			{
				v=a[i][y];
				g[u][v]=min(g[u][v],1ll*t[i][x]+t[i][y]);
				g[v][u]=min(g[v][u],1ll*t[i][x]+t[i][y]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	int x,y;
	ll ans;
	while(q--)
	{
		cin>>x>>y;
		ans=inf;
		for(int i=1;i<=tp[x];i++)
		{
			for(int j=1;j<=tp[y];j++)
			{
				ans=min(ans,t[x][i]+t[y][j]+g[a[x][i]][a[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}