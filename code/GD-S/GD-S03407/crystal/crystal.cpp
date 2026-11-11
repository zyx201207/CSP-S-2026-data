//Author: mairuisheng
//#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char s;
	s=getchar();
	while(s<48||s>57)
	{
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>47&&s<58)
	{
		x=(x<<3)+(x<<1)+s-48;
		s=getchar();
	}
	return x*f;
}
constexpr int N=5e5+5;
int n,m;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	int i,re=m,l=n-1,ans=0;
	for(i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	for(i=n;i>0;--i)
	{
		while(l>0&&a[i]-a[l]<=re)
		{
			re-=a[i]-a[l];
			--l;
		}
		ans=max(ans,i-l);
		re+=(a[i]-a[i-1])*(i-l-1);
	}
	printf("%lld",ans);
	return 0;
}
