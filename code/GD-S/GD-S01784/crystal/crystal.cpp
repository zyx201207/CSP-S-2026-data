#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N];
ll dis[N]; 
int n;
ll m;
ll f(ll x)
{
	for (int i=1;i<=n;i++)
	{
		dis[i]=abs(x-a[i]);
	}
	sort(dis+1,dis+n+1);
	ll mm=m;
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		if (mm>=dis[i])
		{
			ans++;
			mm-=dis[i];
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	ll sum=0LL;
	for (ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if (sum%n==0)
	{
		printf("%lld",f(sum/n));
	}
	else
	{
		printf("%lld",max(f(sum/n),f(sum/n+1)));
	}
	return 0;	
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
