#include <cstdio>
using namespace std;
const int N=505,M=490905;
int c,n,m,d,q,k[N],w[M],a[N][M],t[N][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++) scanf("%d%d",&a[i][j],&t[i][j]);
	}
	for(int i=1;i<=q;i++)
	{
		long long ans=0;int x,y;
		scanf("%d%d",&x,&y);
		ans+=w[x];
		for(int j=x;j<=y;j++)
		{
			ans+=t[x][j];
		}
		ans+=w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
