#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500000+10;
ll a[maxn],sum[maxn];
ll f(ll m,ll p){
	ll i=1;
	while(i<=p){
		ll ne=llabs(a[p]*(p-1)-(sum[p-1]-sum[i-1]));
		if(m>=ne){
			break;
		}
		i++;
	}
	return p-i+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,i,m;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll ans=0;
	for(i=1;i<=n;i++) ans=max(ans,f(m,i));
	cout<<ans;
	return 0;
}
