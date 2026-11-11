#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, num, ans;
vector<ll> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	ans = a.size();
	num = a[ans - 1];
	for (int i = 1; i < m; i++) {
		num = num & a[ans - i - 1];
	}
	cout << num;
	return 0;
}
