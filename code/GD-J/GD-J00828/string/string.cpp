#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
ll a[N];
char c[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	
	ll l = 1, r = n;
	ll ans = 0;
	while(l <= r){
		if(c[l] == c[r]){
			if(abs(a[l] - a[r]) != 0){
				if(a[l] > a[r]){
					a[l] -= a[r];
					r--;
				}else{
					a[r] -= a[l];
					l++;
				}
			}else{
				l++, r--;
			}
		}else{
			if(a[l] <= a[r]){
				ans += a[l];
				a[r] -= a[l];
				l++;
			}else{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
