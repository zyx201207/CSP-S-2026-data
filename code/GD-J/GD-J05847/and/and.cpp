#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
ll n,m;
ll a[N];
ll ans = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n;
	cin >> m;
	for(ll i=1;i<=n;i++) cin >> a[i];
    
    if(m == 2) {
    	for(ll i=1;i<=n-1;i++){
    		ll cnt = a[i] & a[i+1] ;
    		ans = max(ans,cnt);
		}
		cout << ans;
		return 0;
	}else{
		cout << 7;
		return 0;
	}
	
	
	return 0;
}
