#include<cstdio>
#define ll long long int 
using namespace std;
const int N=2e6,_N=5e3;
ll a[N+5];
ll f[_N+5][_N+5],g[_N+5][_N+5];
void slv()
{
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n<=1e3)
	{
		for(int ln=1;ln<n;ln++)
		{
			for(int i=1;(i+ln)<=n;i++)
			{
				int j=i+ln;
				if((a[j]-a[i])<=m)
				{
					f[i][j]=1,g[i][j]=1;
					continue;
				}
				f[i][j]=n+1,g[i][j]=0;
				for(int k=i+1;k<j;k++)
				{
					if(f[i][k]!=1)
					{
						break;
					}
					if((f[i][k]+f[k][j])==f[i][j])
					{
						g[i][j]+=(g[i][k]*g[k][j]);
					}
					if((f[i][k]+f[k][j])<f[i][j])
					{
						f[i][j]=f[i][k]+f[k][j],g[i][j]=g[i][k]*g[k][j];
					}
				}
			}
		}
		ll ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=(g[i][j]==2ll);
			}
		}
		printf("%lld\n",ans);
	}
	else
	{
		printf("0\n");
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	for(int i=1;i<=T;i++)
	{
		slv();
	}
	return 0;
}
