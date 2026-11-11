#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int n, a[N], pre[N], ans;
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		pre[i] = pre[i - 1] + a[i];
	}
	int j = n;
	for(int now, i = 1; i <= n; ++i) {
		bool flag = false;
		now = a[i];
		if(pre[i] > pre[n] / 2) {
			now = a[i] - (pre[i] - pre[n] / 2);
			flag = true;
		}
		while(j > 0 && now > 0) {
			int val = a[j];
			if(val > now) {
				ans += (c[i] != c[j]) * now;
				a[j] -= now;
				now = 0;
				break;
			}
			else {
				ans += (c[i] != c[j]) * val;
				a[j] = 0;
				now -= val;
			}
			-- j;
		}
		if(flag) break;
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

100 pts?
³È 
*/
