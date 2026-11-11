#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],s[N];
ll n,m;
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,ans=1;
	for(ll i=1;i<=n;i++){
		while(l<=i&&(i-l+1)*a[i]-(s[i]-s[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
	return 0;
}
