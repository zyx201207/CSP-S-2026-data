//Because of you,I'm not afraid.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
		{x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=5e5+7;
ll n,m;
ll ans=0;
ll a[N];
ll sum[N];
bool cmp(ll x,ll y){return x<y;}
int chk(ll x,ll mid)
{
	if(a[x]*(x-mid)-(sum[x]-sum[mid])<=m)
		return 1;
	return 0;
}
void q(ll x,ll l,ll r)
{
	if(l>r)return;
	ll mid=(l+r)>>1;
	if(chk(x,mid))
	{
		ans=max(ans,x-mid);
		r=mid-1;
	}
	else l=mid+1;
	q(x,l,r);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j;
	n=read();m=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++)
		q(i,0,i-1);
	printf("%lld",ans);
	return 0;
}
