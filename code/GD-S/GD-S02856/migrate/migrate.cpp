#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define LL long long
#define int long long
using namespace std;
const int N=2e6+10;
const LL INF=1e18+10;
inline LL read()
{
	int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-48;
	return x*f;
}
LL n,d,ans;
LL tot;
LL x[N];
bool check(int l,int r)
{
	tot=0;
	if(x[r]-x[l]<=d) return 0;
	for(int i=l;i+1<=r;i++)
		if(x[i+1]-x[i]>d) return 0;
	int tot=0;
	for(int i=l;i+3<=r;i++)
		if(x[i+3]-x[i]>d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d) tot++;
	if(tot==1) return 1;
	return 0;
}
void init()
{
	n=read(),d=read(),ans=0;
	rep(i,1,n)
	{
		x[i]=read();
	}
}
void solve1()
{
	rep(i,1,n)
	{
		rep(j,i+1,n)
		{
			if(check(i,j))
			{
				ans++;
//				printf("(%d,%d)\n",i,j);
			}
		}
	}
	printf("%lld\n",ans);
}
void solve2()
{
	LL len=x[2]-x[1];
	LL k=(d/len);
	ans=max(n-k*2+1,0ll);
	if(d<=len) ans=0;
//	printf("len=%lld k=%lld d=%lld\n",len,k,d);
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--)
	{
		init();
		if(c==11||c==12) solve2(); 
		else solve1();
//		solve2();
	}
	return 0;
}

