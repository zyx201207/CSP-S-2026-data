//GZ-S00272  贵阳市第三实验中学  闫张玴 
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int C, T, mi;
int n, d, a[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--) {
		cin >> n >> d;
		mi = LONG_LONG_MAX;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			if(i >= 2) mi = min(mi, a[i] - a[i-1]);
		}
		if(mi > d) {
			cout << 0 << "\n";
			continue;
		}
		if(C == 11 || C == 12) {
			int du = d/(a[2] - a[1]);
			if(d == 1) {
				cout << 0 << "\n";
			} else {
				cout << n-2 << "\n";
			}
			continue;
		}
		cout << 1 << "\n";
	}
	return 0;
}
