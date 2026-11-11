#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
ll n,m,a[N],dif[N],maxn=1;
bool sp=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		dif[i]=a[i]-a[i-1];
		if(i>2&&dif[i]!=dif[i-1])
			sp=false;
	}
	if(sp)
	{
		ll sum=0,ans=1;
		for(;ans<n;ans++)
		{
			if(sum+ans*dif[n]>m)
				break;
			sum+=ans*dif[n];
		}
		printf("%lld",ans);
		return 0;
	}
	for(ll i=2,sum;i<=n;i++)
	{
		sum=0;
		for(ll j=i+maxn-1;j<=n;j++)
		{
			sum+=dif[j]*(j-i+1);
			if(sum>m)
			{
				maxn=max(maxn,j-i+1);
				break;
			}
		}
	}
	printf("%lld",maxn);
	return 0;
}
