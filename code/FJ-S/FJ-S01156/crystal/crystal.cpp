#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
ll n,m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=1;
	ll ans=1,nw=0;
	while(l<=r&&r<n)
	{
		while(nw<=m&&r<n)
		{
			r++;
			nw+=(a[r]-a[r-1])*(r-l); 
			if(nw<=m)ans=max(ans,r-l+1);
		}
		while(nw>m&&l<r)
		{
			l++;
			nw-=(a[r]-a[l-1]);
		}
	}
	cout<<ans;
	return 0;
}
