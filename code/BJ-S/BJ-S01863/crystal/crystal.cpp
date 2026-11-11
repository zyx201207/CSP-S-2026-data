#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	ll mina = 1e9, maxa = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mina = min(mina, a[i]);
		maxa = max(maxa, a[i]);
	}
	sort(a.begin(), a.end());
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll cnt = m;
		ll tmp = 1;
		for(int j = i - 1; j >= 0; j--){
			if(a[i] - a[j] <= cnt){
				cnt -= (a[i] - a[j]);
				tmp++;
			}
			else{
				break;
			}
		}
		ans = max(ans, tmp);
	}
	
	cout << ans << endl;
	return 0;
}
