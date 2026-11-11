#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+10;
LL n,d,x[N],L[N],R[N];
LL f[N],g[N];
LL cid;
void init()
{
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n&&x[j+1]-x[i]<=d) j++;
		R[i]=j;
	}
	for(int i=1,j=1;i<=n;i++)
	{
		while(x[i]-x[j]>d) j++;
		L[i]=j;
	}
}
LL c[N];
LL zxz(LL r,LL x,LL y)
{
	return x==y||r<=min(x,y);
}
void solve()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",x+i);
	init();
	LL ans=0;
	for(LL r=n;r>=1;r--)
	{
		for(int i=r;i>=1;i--)
		{
			c[i]=0;
			if(R[i]<r&&zxz(r,R[R[i]],R[R[i]-1]))
			{
				c[i]++;
				if(zxz(r,R[R[i]],R[R[i]-2])&&R[i]-2>i) c[i]++;
				else if(zxz(r,R[R[i-1]],R[R[i]])) c[i]++;
			}
		}
		for(int l=r;l>=1;l--)
		{
			c[l]+=c[R[l]];
			if(c[l]-(R[l]<r&&zxz(r,R[R[l]],R[R[l]-1])&&zxz(r,R[R[l-1]],R[R[l]])&&!(zxz(r,R[R[l]],R[R[l]-2])&&R[l]-2>l))==1)
			{
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++) c[i]=0;
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	LL T; scanf("%lld%lld",&cid,&T);
	while(T--) solve();
	return 0;
}
