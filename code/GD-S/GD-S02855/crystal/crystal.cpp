#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf (ll)(1e18)

ll arr[500005];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n , m; cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	sort(arr + 1 , arr + n + 1);
	
	bool mark = true;
	ll diff = arr[2] - arr[1];
	for(int i = 2;i < n;i++){
		if(diff != arr[i + 1] - arr[i]){
			mark = false;
			break;
		}
	}
	
	if(mark){
		ll ans = 1;
		for(int i = 1;i < n;i++) {
			m -= arr[i + 1] - arr[i];
			if(m < 0) break;
			ans++;
		}
		cout << ans << endl;
	}
	
	ll ans = 0;
	for(int i = 2;i <= n;i++) {
		ll cost = 0;
		ll ptr = i;
		for(int j = i - 1;j >= 1;j--){
			if(cost + arr[i] - arr[j] > m) break;
			cost += arr[i] - arr[j];
			ptr--;
		}
		
		ans = max(ans , i - ptr + 1);
	}
	cout << ans << endl;
	
	return 0;
} 
