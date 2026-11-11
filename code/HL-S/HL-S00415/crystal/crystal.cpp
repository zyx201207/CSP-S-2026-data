#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll a[N],sum[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1; i<=n; i++) if(sum[i]+m>=a[i]*i) ans=max(ans,i);
	cout<<ans;
	return 0;
}