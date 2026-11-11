#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll ans=-0X7FFFFFFF;
void dfs(ll now,ll jsq,ll num)
{
	if(jsq>m)return;
	if(jsq==m)
	{
		ans=max(ans,num);
		return;
	}
	for(ll i=now+1;i<=n;i++)
	{
		dfs(i,jsq+1,(num&a[i]));
	}
	return;
}
int main()
{
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n-m;i++)
	{
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}

