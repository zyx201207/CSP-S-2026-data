#include<bits/stdc++.h>
using namespace std;
long long T,n,d,a[3000009],R[3000009],L[3000009],f[3000009],F[3000009],g[3000009],G[3000009],b,c,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	for(int t=1;t<=T;++t)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
			f[i]=0;
			F[i]=0;
			g[i]=0;
			G[i]=0;
		}
		R[n]=n;
		for(int i=n-1;i>=1;--i)
		{
			R[i]=R[i+1];
			while(a[R[i]]-a[i]>d)--R[i];
		}
		L[1]=1;
		for(int i=2;i<=n;++i)
		{
			L[i]=L[i-1];
			while(a[i]-a[L[i]]>d)++L[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(R[i]>i)
			{
				++F[R[i]];
			}
			f[i]=F[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(R[i]>i&&L[R[i]]==i)
			{
				f[R[i]]+=f[i];
			}
		}
		for(int i=n;i>=1;--i)
		{
			if(L[i]<i)
			{
				++G[L[i]];
			}
			g[i]=G[i];
		}
		for(int i=n;i>=1;--i)
		{
			if(L[i]<i&&R[L[i]]==i)
			{
				g[L[i]]+=g[i];
			}
		}
		for(int i=2;i<=n;++i)
		{
			if(R[i-1]>i&&L[i]<i-1)
			{
				b=F[i];
				c=G[i-1];
				if(R[L[i-1]]==i)
				{
					b+=f[L[i-1]];
				}
				if(L[R[i]]==i-1)
				{
					c+=g[R[i]];
				}
				ans+=b*c;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
