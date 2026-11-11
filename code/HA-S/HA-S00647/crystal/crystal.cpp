#include<bits/stdc++.h>
using namespace std;
typedef long long ll;		
constexpr int N=5e5+5;
ll n=0,m=0,a[N]={},sum[N]={};
bool check(int lim)
{
	ll i=0,r=0;
	for(i=1;i+lim-1<=n;i++)
	{
		r=i+lim-1;
		if(lim*a[r]-(sum[r]-sum[i-1])<=m)
			return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);		
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i=0,l=0,r=0,mid=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	l=1,r=n;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	if(check(r))
		cout<<r;
	else
		cout<<l;
	return 0;
}
