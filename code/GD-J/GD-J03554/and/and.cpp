#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010];
int pw(int x, int y) {
	int as = 1;
	for(int i=1; i<=y; i++) {
		as *= x;
	}
	return as;
}
bool checkA(int x) {
	for(int i=0; ;i++) {
		if(pw(2, i)-1 == x) {
			return 1;
		} if(pw(2, i)-1 > x) {
			return 0;
		}
	}
}
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	bool A = 1;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(!checkA(a[i])) {
			A = 0;
		}
	}
	
	int ans = 0;
	if(A) {
		sort(a+1, a+n+1, cmp);
		cout << a[m];
		return 0;
	} if(m == 1) {
		sort(a+1, a+n+1, cmp);
		cout << a[1];
		return 0;
	} if(m == n) {
		ans == a[1];
		for(int i=2; i<=n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	} if(m == 2) {
		ans = -1;
		for(int l=1; l<n; l++) {
			for(int r=l+1; r<=n; r++) {
				ans = max(a[l] & a[r], ans);
			}
		}
		cout << ans;
		return 0;
	}
	
	ans = a[1];
	for(int i=2; m>1; i++, m--) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
