#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N=2e6+5;

int testid,AAA;
int n;LL d;
LL x[N];
int rchR[N],rchL[N];
int f[N],g[N]; LL sf[N],sg[N];
LL sumf(int l,int r)
{
	if (l>r)return 0;
	return sf[r]-sf[l-1];
}
LL sumg(int l,int r)
{
	if (l>r)return 0;
	return sg[l]-sg[r+1];
}
int len(int l,int r)
{
	if (l>r)return 0;
	return r-l+1;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&testid,&AAA);
	while (AAA--)
	{
		scanf("%d%lld",&n,&d);
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		for (int i=n,r=n;i>=1;i--)
		{
			while (x[r]-x[i]>d)
				r--;
			rchR[i]=r;
		}
		for (int i=1,l=1;i<=n;i++)
		{
			while (x[i]-x[l]>d)
				l++;
			rchL[i]=l;
		}
		for (int i=1;i<=n;i++)
		{
			f[i]=1+sumf(rchL[i],min(rchL[i+1]-1,i-1));
			sf[i]=sf[i-1]+f[i];
		}
		sg[n+1]=0;
		for (int i=n;i>=1;i--)
		{
			g[i]=1+sumg(max(rchR[i-1]+1,i+1),rchR[i]);
			sg[i]=sg[i+1]+g[i];
		}
		LL ans=0;
		for (int i=2;i<n-1;i++)
		{
			// while (rchR[rgl+1]<i+2)rgl++;

			int l=rchL[i+1],r=rchR[i];
			if (l<i&&r>i+1&&rchL[i+2]>l&&rchR[i-1]<r)
			{
				LL tmpl,tmpr;
				if (rchL[i]==l)tmpl=f[l]+len(l+1,rchL[i+2]-1);
				else tmpl=len(l,rchL[i+2]-1);
				if (r==rchR[i+1]) tmpr=len(rchR[i-1]+1,r-1)+g[r];
				else tmpr=len(rchR[i-1]+1,r);
				ans+=(LL)tmpl*tmpr;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*

*/