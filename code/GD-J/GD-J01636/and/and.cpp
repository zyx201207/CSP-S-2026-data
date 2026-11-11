#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
ll n,m,ans,a[maxn],dp[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<ll>());
	for(ll j=1;j<=min(n,50ll);j++){
		ll s=a[j];
		for(ll i=2;i<=m;i++){
			s=(s&a[i]);
		}
		ans=max(ans,s);
	}
	cout<<ans<<endl;
	return 0;
}
