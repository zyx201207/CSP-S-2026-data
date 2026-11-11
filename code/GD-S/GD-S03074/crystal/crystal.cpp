#include<bits/stdc++.h>
using namespace std;

#define int long long

int check(int x, vector<int>& a, int n) {
	queue<int> q;
	
	long long sum = 0;
	for(int i = 1; i < x; i++) {
		q.push(a[i]);
		sum += a[i];
	}
	long long ans = 4e18;
	for(int i = x; i <= n; i++) {
		q.push(a[i]);
		int now = a[i] * (x - 1) - sum;
		ans = min(ans, now);
		sum = sum - q.front() + a[i];
		q.pop();
	}
	return ans;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	
	int l = 1, r = n;
	int ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		int need = check(mid, a, n);
		if(need <= m) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}

/*
5 5
1 2 4 8 9
*/
