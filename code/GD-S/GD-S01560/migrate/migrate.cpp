#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5,L=1e4+3;
int C,T,n,f[L];
ll x[N],d,g[L],sum[L],ans;
int q[L];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		ans=0;
		if(C<=10)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
					f[j]=n+1,g[j]=0,sum[j]=0;
				f[i]=0,g[i]=1;
				int hd=1,tl=1;
				q[1]=i,sum[0]=1;
				for(int j=i+1;j<=n;j++)
				{
					while(hd<=tl && abs(x[j]-x[q[hd]])>d) sum[f[q[hd]]]-=g[q[hd]],hd++;
					if(hd>tl) break;
					f[j]=f[q[hd]]+1,g[j]=sum[f[q[hd]]];
					if(g[j]==2)
					{
						ans++;
					}
//					printf("%d %d  %d\n",i,j,g[j]);
					q[++tl]=j,sum[f[j]]+=g[j];
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		if(11<=C&&C<=12)
		{
			if(n==1||abs(x[n]-x[1])<=d)
			{
				printf("0\n"); continue;
			}
			ll cf=x[2]-x[1];
			if(d<=cf)
			{
				printf("0\n"); continue;
			}
			ans=max(0ll,n-(d/cf)*2ll+1ll);
			printf("%lld\n",ans);
			continue;
		}
		if(13<=C&&C<=14)
		{
			if(n&1)
			{
				if(d>x[(n+1)/2]-x[1])
				{
					printf("0\n"); continue;
				}
				printf("2\n");
			}
			else
			{
				if(d>x[n]-x[n/2])
				{
					printf("0\n"); continue;
				}
				printf("1\n");
			}
			continue;
		}
	}
	return 0;
}
