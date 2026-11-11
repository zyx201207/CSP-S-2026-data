#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n, tn = 0;
	cin >> n;
	string s;
	for(ll i = 1; i <= n; i++){
		ll a;
		char c;
		scanf("%lld %c", &a, &c);
		tn += a;
		for(ll j = 1; j <= a; j++){
			s += c;
		}
	}
	ll l = 0, r = tn - 1, cnt = 0;
	while(l <= r){
		if(s[l] != s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	
	return 0;
}

