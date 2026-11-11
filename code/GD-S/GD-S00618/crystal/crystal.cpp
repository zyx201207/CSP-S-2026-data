#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll N=1e6+10;
ll a[N];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=0;
	//-------------------------------------
	for(ll i=2;i<=n;i++){
		ll x=0,sum=0;
		for(ll j=1;j<=i;j++){
			if(x+(a[i]-a[j])<=m){
				sum++;
				x+=a[i]-a[j];
//				cout<<x<<' '<<sum<<'\n';
				ans=max(sum,ans);
			}
			
		}
//		cout<<'\n';
	}
	cout<<ans;
	return 0;
} 
