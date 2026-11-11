#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
const ll inf=1e15;
int c,n,m,d,q,tot,len,sta,cst,to[N][25],x,y,l[N];
ll w[N],a[N][25],f[M][M],ans;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>len;
		for(int j=1;j<=len;j++)
			cin>>sta>>cst,a[sta][++l[sta]]=cst,to[sta][l[sta]]=i;
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++) f[i][j]=inf;
		f[j][j]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1,v;j<=l[i];j++)
		{
			v=to[i][j];
			for(int k=j+1,vx;k<=l[i];k++)
			{
				vx=to[i][k];
				f[v][vx]=min(f[v][vx],a[i][j]+a[i][k]);
				f[vx][v]=min(f[vx][v],a[i][j]+a[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{ for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);}
	}
	while(q--)
	{
		cin>>x>>y;
		ans=inf;
		for(int i=1,v;i<=l[x];i++)
		{
			v=to[x][i];
			for(int j=1;j<=l[y];j++)
				ans=min(ans,a[x][i]+a[y][j]+f[v][to[y][j]]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

