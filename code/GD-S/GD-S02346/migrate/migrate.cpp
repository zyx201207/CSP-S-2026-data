#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	int n, d, x[maxn], ans = 0;
	while(t --) {
		cin >> n >> d;
		for(int i = 0; i < n; i++) {
			cin >> x[i];
		} 
		for(int i = 0; i < n; i++) {
			if(i + d + 1 < n) ans ++;
		}
		cout << ans <<endl;
	} 
	return 0;
}
