#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int M=5e5+100,N=520,MOD=1e9+7;const ll inf=(ll)1e15;
int w[M],p[M][21],h[M][21];ll v[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;memset(v,0x3f,sizeof(v));
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k,a,t;scanf("%d",&k);v[i][i]=0;
		while(k--) scanf("%d%d",&a,&t),p[a][++p[a][0]]=i,h[a][++h[a][0]]=t;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=h[i][0];j++)
			for(int k=1;k<=h[i][0];k++)
				v[p[i][j]][p[i][k]]=min(v[p[i][j]][p[i][k]],ll(h[i][j]+h[i][k]));
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=1;j<=n;j++) v[i][j]=min(v[i][j],v[k][i]+v[k][j]);
	while(q--)
	{
		int x,y;scanf("%d%d",&x,&y);ll e=inf;
		for(int j=1;j<=h[x][0];j++)
			for(int k=1;k<=h[y][0];k++) e=min(e,v[p[x][j]][p[y][k]]+h[x][j]+h[y][k]);
		printf("%lld\n",e+w[x]+w[y]);
	}
	return 0;
}
