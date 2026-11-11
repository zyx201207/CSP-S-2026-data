/**********************
 ~AUTHOR BY "ILWF^_^" 
 ~author by "ILWF^_^" 
**********************/
#include<bits/stdc++.h>
#define LM LLONG_MAX
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 500005;
const ll mod = 1e9 + 7;
ll a[N] , b[N];
ll n , m , q;
bool check(ll mid , ll r){
	ILW (a[r] * (r - mid + 1) - b[r] + b[mid - 1] <= m);
}
ll ans = 0;
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1;i <= n;i++) b[i] = b[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		ll l = 1 , r = i , res = -1;
		while(l <= r){
			ll mid = l + (r - l) / 2;
			if(check(mid , i) == true) r = mid - 1 , res = mid;
			else l = mid + 1;
		}
		if(res != -1) ans = max(ans , (ll)i - res + 1);
	}
	cout << ans;
}
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F; 
}
