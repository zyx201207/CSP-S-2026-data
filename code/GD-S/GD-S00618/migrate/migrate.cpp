#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll N=1e6+10;
ll a[N];
ll c,kk,n,m;
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	
	for(ll i=2;i<=n;i++){
		if(abs(a[i]-a[i-1])>m){
			n=i-1;
			break;
		}
	}
	if(m*m>n){
		cout<<0<<'\n';
		return;
	}
	ll ans=1;
	ans+=n-m*m;
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>kk;
	while(kk--){
		solve();	
	}
	return 0;
} 
