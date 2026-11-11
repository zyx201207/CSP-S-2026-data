#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e6+10;
long long a[N];
long long addd(int u) {
	int ans = 0;
	for(int i = 1; i <= u; i++) {
		ans += i;
	}
	return ans;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	for(int i = 1; i <= t; i++) {
		long long n, d;
		cin >> n >> d;
		for(int j = 1; j <= n; j++) {
			cin >> a[i];
		}
		long long cnt = a[2]-a[1];
		long long u = d/cnt;
		if(u == 0) { cout << 0; continue; }
		cout << u*n-addd(u) << endl;
	}
	
	return 0;	
}
