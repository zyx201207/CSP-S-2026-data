#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;
using ll = __int128;
int n,ans;
ll m;
ll a[N],sum[N];
inline ll read()
{
	ll x=0,f=1; char ch=getchar();
	while(ch>'9' || ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll tar=m-a[i]*i-a[i]+sum[i];
		int l=0,r=i,res=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(sum[mid-1]-a[i]*mid>tar) l=mid+1;
			else r=mid-1,res=mid;
		}
		ans=max(ans,i-res+1);
	}
	printf("%d",ans);
	return 0;
}
