#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[2000005],ans = 0;
bool cmp(ll x,ll y)
{
	return x>y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i = 2;i<=m;i++)
	{
		ans = a[i]&a[i-1];
	}
	cout<<ans;
	return 0;
}
