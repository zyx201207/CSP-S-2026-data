#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=5e5+10;
ll n,m;
ll a[N];

int main()
{
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	
//	freopen("crystal3.in","r",stdin);freopen("crystal.out","w",stdout);
	
//	system("fc crystal.out crystal3.ans");
//	return 0;
	
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	
	ll ans=1;
	ll r=1,sum=0;
	for(ll l=1;l<=n;++l)
	{
		while(sum+(r-l+1)*(a[r+1]-a[r])<=m&&r+1<=n)
		{
			sum+=(r-l+1)*(a[r+1]-a[r]);
			++r;
		}
		ans=max(ans,r-l+1);
		if(r==n)
		{
			break;
		}
		sum-=a[r]-a[l];
	}
	printf("%lld",ans);
	
	return 0;
}
