#include<bits/stdc++.h>
#define Ibuki Suika
#define ll long long
int const X=5e5+10;
using namespace std;
ll n,m,ans=-1,t;
ll a[X],p[X];
bool check(int x,int y)
{
	if(a[y]*y-p[y]-(a[y]*(x-1)-p[x-1])<=m) return 1;
	else return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	p[0]=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		p[i]=a[i]+p[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<r)
		{
			ll mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
		
	}

	printf("%lld",ans);
	
	return 0;
}