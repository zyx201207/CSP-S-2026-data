#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],sum[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll l=1,r=1;l<=n;l++)
	{
		r=max(r,l);
		while(r<=n&&a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m) r++;
		ans=max(ans,r-l);
	}
	cout<<ans;
}
