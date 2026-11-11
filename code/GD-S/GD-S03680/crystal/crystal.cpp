#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll x,ll y)
{
	return x<y;
}
ll n,m,a[500010],ans,s[500010];
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(ll i=1,j=0;i<=n;i++)
	{
		while(s[i]-s[j]+m<(i-j)*a[i])j++;
		ans=max(ans,i-j);
	}
	cout<<ans<<endl;
	return 0;
}
