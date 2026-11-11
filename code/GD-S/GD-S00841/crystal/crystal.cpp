#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 511451;
ll a[N];
ll n,k = 0;
ll m;

bool check1(ll mid){
	ll ans = 0;
	ll rm = m;
	for(auto up = upper_bound(a + 1, a + n + 1, mid) - 1; up >= a; up--){
		ll need = mid - *up;
		if(need < 0 || need > rm) break;
		rm -= need;
		ans++;
	}
	//cout << mid << ':' << ans << endl;
	bool choose = ans >= k;
	k = max(ans, k);
	return choose;
}
bool check2(ll mid){
	ll ans = 0;
	ll rm = m;
	for(int i = 1; i <= n; i++){
		ll need = mid - a[i];
		if(need < 0 || need > rm) break;
		rm -= need;
		ans++;
	}
	//cout << mid << ':' << ans << endl;
	bool choose = ans >= k;
	k = max(ans, k);
	return choose;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	ll mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + n + 1, less<ll>());
	ll l = mn, r = mx, mid = 0, ans = 0;
	if(r - l <= 250 && n > 5000){
		for(;l<=r;l++) check1(l);
	}
	else{
		while(l <= r){
			mid = (r + l) >> 1;
			//cout << l << ' ' << r << ' ' << mid << endl;
			if(check2(mid)){
				l = mid + 1;
				ans = mid;
			}
			else {
				r = mid - 1;
			}
		}
	}

	
	cout << k;
	return 0;
} 
