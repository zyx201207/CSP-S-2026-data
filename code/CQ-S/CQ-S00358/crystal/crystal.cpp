#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
ll a[MAXN];
int n;
ll m;
bool f(ll x)
{
	ll sum=0;
	for(int i=1;i<x;i++) sum+=a[x]-a[i];
	for(int i=x;i<=n;i++)
	{
		if(sum<=m) return 1;
		sum+=x*(a[i+1]-a[i]);
		sum-=a[i+1]-a[i-x+1];
	}
	return 0;
}
ll binary_answer(ll l,ll r)
{
	while(l<r)
	{
		ll mid=l+r+1>>1;
		if(f(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<binary_answer(1,n);
	return 0;
}

