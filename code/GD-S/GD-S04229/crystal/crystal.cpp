#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],s[N];
bool chk(ll l,ll r)
{
	return (r-l+1)*a[r]-(s[r]-s[l-1])<=m;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<r)
		{
			ll mid=(l+r)/2;
			if(chk(mid,i))
				r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans; 
	return 0;
} 
