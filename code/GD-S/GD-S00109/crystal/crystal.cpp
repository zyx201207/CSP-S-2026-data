#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;
ll a[N];
ll n, m;

bool check(int mid) { // mid is an index
	ll sum = m;
	for(int i = 1; i < mid; i++) {
		sum -= a[mid] - a[i];
		if(sum < 0) return false;
	}
	return true;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	int l = 1, r = n, mid;
	while(l != r) {
		mid = l + (r - l + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << l << '\n';
	
	return 0;
}
