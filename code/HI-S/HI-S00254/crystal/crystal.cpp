#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll n,m,maxm,minm=1e13,ans,t,js,k;
ll a1[maxn],a2[maxn];
bool cmp(ll x,ll y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a1[i]);
	}
	sort(a1+1,a1+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		a2[i]+=a2[i-1]+a1[i];
	}
	int j=1;
	for(int i=1;i<=n;i++)
	{
		t=(i-j+1)*a1[i];
		js=t-(a2[i]-a2[j-1]);
		while(js>m&&j<i)
		{
			t=(i-j+1)*a1[i];
			j++;
			js=t-(a2[i]-a2[j-1]);
		}
		k=i-j+1;
		ans=max(ans,k);
	}
	printf("%lld",ans);
	return 0;
}
