#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans; 
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(ll i=1;i<=n;i++){
			ll a;
			cin>>a;
			ans=max(ans,a);
		}
		cout<<ans;
	}if(m==n){
		ll a;
		cin>>a;
		ans=a;
		for(ll i=2;i<=n;i++){
			cin>>a;
			ans=(ans&a);
		}
	
	}else {
		ll a[200005];
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		ans=a[n];
		for(ll i=n;i>=m;i--) ans=(ans&a[i]);	
    }
	cout<<ans;
	return 0;
}
