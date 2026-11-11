#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 5;

int n, m, a[MAXN], l, r, ans;
int s[MAXN];

bool check(int x) {
	int sum = 0, su = 0;
	
	for (int i = x; i <= n; i++) {
		su = s[i - 1] - s[i - x];
		sum = a[i] * (x - 1) - su;
		
		if (sum <= m) {
			return true;
		}
	}
	
	
	return false;
}

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	
	l = 1, r = n;
	
	while(l <= r) {
		int mid = (l + r) / 2;
		//cout << l << " " << r << " " << mid << endl;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} 
		else {
			r = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}
