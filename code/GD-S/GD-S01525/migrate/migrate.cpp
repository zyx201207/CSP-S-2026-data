#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e3+10;
int a[N],b[N][N],c[N][N],st[N],siz[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int op,T;
	scanf("%lld%lld",&op,&T);
	while(T--)
	{
		int n,m;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			b[i][i]=0;
			c[i][i]=1;
			for(int j=1;j<i;j++)
			{
				c[j][i]=0;
				if(a[i]-a[j]<=m)
				{
					c[j][i]=1;
				}
				while(a[i]-a[st[j]]>m&&j<i)
				{
					siz[j]-=c[j][st[j]];
					st[j]++;
				}
				if(siz[j]<=0)
				{
					siz[j]=0;
					for(int k=st[j];k<=i;k++)
					{
						if(b[j][k]!=b[j][st[j]])
						{
							break;
						}
						siz[j]+=c[j][k];
					}
				}
				b[j][i]=b[j][st[j]]+(st[j]!=i)?1:0;
				c[j][i]=siz[j];
			}
			st[i]=i;
			siz[i]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(c[i][j]==2)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
