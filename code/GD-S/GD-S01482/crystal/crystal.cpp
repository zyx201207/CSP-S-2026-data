#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,k;cin >> n >> k;
	ll cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt += a[i];
	}
	double d = cnt / n;
	ll mid = 0;
	if(d - cnt / n > 0.5){
		mid = cnt / n + 1;
	}else{
		mid = cnt / n;
	}
	//cout << mid;
	sort(a + 1,a + n + 1,greater<int>());
	ll ans = 0;
	for(ll i = mid;i >= 1;i--){
		ll l = k;
		ll cnt = 0;
		for(int j = 1;j <= n && l != 0;j++){
			//cout << j << endl;
			if(a[j] < mid){
				a[j]++;
				l--;
				j--;
			}else if(a[j] == mid){
				//cout << j << " ";
				//cout << a[j] << endl;
				cnt++;
			}else if(a[j] > mid){
				l--;
				//cout << a[j];
			}
		}
		//cout << cnt << endl;
		ans = max(cnt,ans);
	}
	cout << ans;
	return 0;
}
