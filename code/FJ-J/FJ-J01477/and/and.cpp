#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200001], maxa = -1;
int andx(int a, int b) {
	return (a & b);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 1) {
		for(int i = 1; i <= n; i++) {
			if(a[i] > maxa) maxa = a[i];
		}
		cout << maxa;
		return 0;
	}
	for(int l = 1; l <= n-1; l++) {
		for(int r = l+1; r <= n; r++) {
			if((a[l] & a[r]) > maxa) maxa = (a[l] & a[r]);
		}
	}
	cout << maxa;
	return 0;
}