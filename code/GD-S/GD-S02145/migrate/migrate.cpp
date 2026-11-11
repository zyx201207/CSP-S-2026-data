#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=2e6+10,M=5010;
int b[N];
ll x[N],g[M][M],h[M][M];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	ll d,ans=0;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		if(n>5000)
		{
			printf("0\n");
			continue;
		}
		memset(g,0x3f,sizeof(g));
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;i++)
			g[i][i]=h[i][i]=1;
		for(int j=1;j<=n;j++)
		{
			b[j]=1;
			for(int k=j-1;k>=1;k--)
				if(x[j]-x[k]>d)
				{
					b[j]=k+1;
					break;
				}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j-1;k>=i;k--)
				{
					if(x[j]-x[k]<=d)
					{
						if(g[i][k]+1==g[i][j]) h[i][j]+=h[i][k];
						if(g[i][k]+1<g[i][j])
						{
							g[i][j]=g[i][k]+1;
							h[i][j]=h[i][k];
						}
					}
					else break;
				}
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(h[i][j]==2) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
