#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
string aty;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		char c;
		ll x;
		cin >> x >> c;
		for(int j = 1; j <= x; ++j) aty += c;
	}
	ll ans = 0;
	for(ll i = 0, j = int(aty.size()) - 1; i <= j; ++i, --j)
		if(aty[i] != aty[j]) ans++;
	cout << ans << endl;
	return 0;
}
