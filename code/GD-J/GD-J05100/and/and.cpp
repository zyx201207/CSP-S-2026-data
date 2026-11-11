#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
ll n, m;
ll a[N], ans = 1, ma = INT_MIN;
int main (){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	ll k = m;
	if (m == 1){
		sort(a+1, a+1+n, greater<int>());
		cout << a[1];
	}
	for (ll i = 1; i <= n-k; i++){
		for (ll j = i+1; j <= i+k; j++){
			ans = (a[i] & a[j]);
			ma = max(ma, ans);
		}
	}
	cout << ma;
	return 0;
}
