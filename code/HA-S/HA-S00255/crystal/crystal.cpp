#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010];
bool cmp(ll k,ll j)
{
	return k<j;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	a[0]=a[1];
	for(ll i=1;i<=n;i++)
	{
		m-=(a[i]-a[i-1])*(i-1);
		if(m>=0)
		ans++;
		if(m<0)
		break;
	}
	cout<<ans;
	return 0;
}
