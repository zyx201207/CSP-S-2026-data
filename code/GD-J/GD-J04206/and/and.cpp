#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
using ll=unsigned long long;
ll n,m,a[200005];
ll ans1;
void dfs(ll now,ll k,ll ans)
{
	if(now==n)
	{
		if(ans==ULONG_LONG_MAX) ans=0;
		if(k!=0) return;
		ans1=max(ans1,ans);
		return;
	}
	if(k>0)
	{
		dfs(now+1,k-1,ans&a[now+1]);
	}//dfs(now+1,k-1,ans&a[now+1]);
	dfs(now+1,k,ans);
}
ll solve1()
{
	dfs(0,m,ULONG_LONG_MAX);
	cout<<ans1<<'\n';
	return 0;
}
ll cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		return solve1();
	}
	else if(n==m)
	{
		ll ans2=ULONG_LONG_MAX;
		for(ll i=1;i<=n;i++)
		{
			ans2&=a[i];
		}
		cout<<ans2<<'\n';
		return 0;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		ll ans3=ULONG_LONG_MAX;
        for(ll i=1;i<=m;i++)
        {
        	ans3&=a[i];
		}
		cout<<ans3<<'\n';
		return 0;
	}
	
	return 0;
}
