#include<bits/stdc++.h>
using namespace std;
int c, t;
void solve() {
	int n; cin >>n;
	long long d, a[5010]; cin >>d;
	for(int i = 1; i <= n; i++) cin >>a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int u = 0;
		for(int j = i + 2; j <= n; j++) {
			if(a[j] - a[j-2] <= d) {
				u++;
			}
			if(j - i <= 2) continue;
			if(u >= 2 && a[j] - a[j-1] <= d) {
				ans++;
			}
		}
	}
	cout <<ans <<endl;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >>c >>t;
	while(t--) {
		solve();
	}
}
