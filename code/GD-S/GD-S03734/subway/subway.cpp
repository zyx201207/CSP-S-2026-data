#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,j[N],k[N];
long long val[505][505];
vector<int> v[N],w[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(register int i=1;i<=m;++i) scanf("%d",&j[i]);
	for(register int i=1;i<=n;++i)
	{
		scanf("%d",&k[i]);
		for(register int j=1;j<=k[i];++j)
		{
			int go,value;
			scanf("%d%d",&go,&value);
			v[i].push_back(go),w[i].push_back(value);
		}
	}
	for(register int i=1;i<=m;++i)
	{
		for(register int j=1;j<=m;++j) val[i][j]=1e18+5;
		val[i][i]=0;
	}
	for(register int i=1;i<=n;++i)
		for(register int j=0;j<k[i];++j)
			for(register int l=j+1;l<k[i];++l)
			{
				int x=v[i][j],y=v[i][l];
				long long value=w[i][j]+w[i][l];
				val[x][y]=min(val[x][y],value);
				val[y][x]=min(val[y][x],value);
			}
	for(register int l=1;l<=m;++l)
		for(register int i=1;i<=m;++i)
			for(register int j=1;j<=m;++j)
				val[i][j]=min(val[i][j],val[i][l]+val[l][j]);
	for(register int i=1;i<=q;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",(j[x]+j[y]+val[x][y]));
	}
	return 0;
}
