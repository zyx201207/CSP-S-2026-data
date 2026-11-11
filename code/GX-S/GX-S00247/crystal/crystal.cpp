#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

ll n, m, ans;
ll a[500001], c[500001];
ll getAns(ll midLoc) {
	ll value = a[midLoc];
	while(a[midLoc+1] == value) {
		midLoc ++;
	}
	for (ll i=1; i<=midLoc; i++) {
		c[i] = a[midLoc] - a[i];
	}
	sort(c+1, c+midLoc+1);
	ll sum = 0, num = 0;
	for (ll i=1; i<=midLoc; i++) {
		if (sum + c[i] <= m) {
			sum += c[i];
			num ++;
		} else break;
	}
	return num;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for (ll i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		//ans += a[i];
	}
	sort(a+1, a+n+1);
	for (ll i=1; i<=n; i++) {
		ans = max(ans, getAns(i));
	}
	cout << ans;
	return 0;
}

