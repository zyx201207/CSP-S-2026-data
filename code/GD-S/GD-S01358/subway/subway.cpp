#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f;
struct node
{
	int w,a[25],b[25],tot=0;
}mb[N];
int n,m;
ll mapa[510][510];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			mapa[i][j]=INF;
		}
		mapa[i][i]=0;
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&mb[i].w);
	}
	for(int i=1;i<=n;++i)
	{
		int e;
		cin>>e;
		for(int j=1;j<=e;++j)
		{
			int x;
			scanf("%d",&x);
			mb[x].a[++mb[x].tot]=i;
			scanf("%d",&mb[x].b[mb[x].tot]);
			int totx=mb[x].tot;
			for(int k=1;k<totx;k++)
			{
				int ii=mb[x].a[k],jj=mb[x].a[totx];
				ll kk=mb[x].b[k]+mb[x].b[totx];
				mapa[ii][jj]=min(mapa[ii][jj],kk);
				mapa[jj][ii]=mapa[ii][jj];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			for(int k=1;k<=n;++k)
			{
				mapa[i][j]=min(mapa[i][j],mapa[i][k]+mapa[j][k]);
				mapa[j][i]=mapa[i][j];
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		int totx=mb[x].tot,toty=mb[y].tot;
		for(int i=1;i<=totx;++i)
		{
			for(int j=1;j<=toty;++j)
			{
				ll k=mapa[mb[x].a[i]][mb[y].a[j]]+mb[x].b[i]+mb[y].b[j];
				ans=min(ans,k);
			}
		}
		ans+=mb[x].w+mb[y].w;
		printf("%lld\n",ans);
	}
	return 0;
}
