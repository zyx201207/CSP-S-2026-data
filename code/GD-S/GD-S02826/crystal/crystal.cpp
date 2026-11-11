#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+100;
ll n,m;
ll a[N],sum[N];
bool check(ll k)
{ll up=0;bool flag=0;
	for(ll r=k,l=1;r<=n;++r,++l)
	{
		up=1ll*k*a[r]-(sum[r]-sum[l-1]);
		if(up<=m)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);cout.tie(nullptr);
cin>>n>>m;
for(int i=1;i<=n;++i)
{
cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
ll l=1,r=n;
while(l<r)
{
	ll mid=(l+r+1)>>1;
	if(check(mid))
	{
		l=mid;
	}
	else r=mid-1;
}
cout<<l;
return 0;
}
