#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N];
ll ans=1;
ll c[N]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	c[1]=0;
	for(ll i=2;i<=n;i++) c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
	ll l=1,r=1;
	while(l<=r&&l<=n&&r<=n)
	{
		ll s=c[r]-c[l]-(l-1)*(a[r]-a[l]);
		if(s<=m) 
		{
			ans=max(ans,r-l+1);
			r++; 
		}
		else l++;
	}
	cout<<ans;
	return 0;
}

