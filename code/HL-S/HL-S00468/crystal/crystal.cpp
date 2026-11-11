#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, i = 0;
	cin >> n >> m;
	ll a[n], sum[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (ll i = n / 2 - 1; i >= 0; i--){
		sum[i] = abs(a[n / 2] - a[i]);
		sum[n - i - 1] = abs(a[n / 2] - a[n - i - 1]);
	}
	sort(sum, sum + n);
	while (m >= 0){
		m -= sum[i];
		i++;
	}
	cout << i;
	
	return 0;
}
