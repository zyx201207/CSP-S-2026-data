#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+20;
ll n,m,i,j,a[N],dp[N],x,ans;
ll fun(ll x)
{
	ll sum=0;
	while(x)
	{
		sum+=(x&1);
		x>>=1;
	}
	return sum;
}
bool cmp(ll a,ll b)
{
	ll x1=fun(a),x2=fun(b);
	return x1>x2||(x1==x2&&a>b);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(i=2;i<=m;i++)
	{
		ans&=a[i];
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
