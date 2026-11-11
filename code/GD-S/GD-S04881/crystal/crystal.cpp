#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

#ifdef __unix
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif

inline ll read()
{
	ll x=0,f=1;
	char ch=' ';
	while (!isdigit(ch))
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void prt(ll x)
{
	if (x>0)
	{
		int stac[20],top=0;
		while (x)
		{
			stac[top++]=x%10;
			x/=10;
		}
		while (top--)
		{
			putchar((char)(stac[top]^48));
		}
	}
	else if (x==0) putchar('0');
	else
	{
		putchar('-');
		x=-x;
		int stac[20],top=0;
		while (x)
		{
			stac[top++]=x%10;
			x/=10;
		}
		while (top--)
		{
			putchar((char)(stac[top]^48));
		}
	}
	return;
}

const int maxn=5e5+10;
const ll INF=1e12+5;

int n,ans;
ll m;
ll a[maxn],sum[maxn];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read()+INF;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,mid;
		while (l<r)
		{
			mid=l+r>>1;
			if (sum[i]-sum[mid-1]>=(i-mid+1)*a[i]-m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	prt(ans),putchar('\n');
	
	return 0;
}
