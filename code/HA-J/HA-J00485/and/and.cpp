#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin ("and.in");
ofstream fout ("and.out");
#define cin fin
#define cout fout

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	sort(a.begin(), a.end(), greater<ll>());
	
	ll ans = a[0];
	for (ll i = 1; i < m; i++) ans = (ans & a[i]);
	
	cout << ans;
	return 0;
}
