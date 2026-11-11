#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005];
ll maxn=0;
void dfs(ll x,ll ret,ll p)
{
	if(x>=m)
	{
		maxn=max(maxn,ret);
		return ;
	}
	else if(p>n-m+1&&x==1)return ;
	else
	{
		for(ll i=p;i<=p+m;i++)
		{
			dfs(x+1,ret&a[i+1],i+1);
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,a[1],1);
	cout<<maxn;
	return 0;
}
