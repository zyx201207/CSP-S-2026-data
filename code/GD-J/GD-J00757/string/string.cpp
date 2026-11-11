#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e5 + 114 + 514;
struct item {
	int a, c;
}items[N];
int ans, n; 
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> items[i].a;
		char c;
		cin >> c;
		items[i].c = c;
	}
	int l = 1, r = n;
	for(int i = 1; i < n; i++) {
		if(items[l].a < items[r].a) {
			if(items[l].c != items[r].c) {
				ans += items[l].a;
			}
			items[r].a -= items[l].a;
			l++;
		}
		else {
			if(items[r].c != items[l].c) {
				ans += items[r].a;
			}
			items[l].a -= items[r].a;
			r--;
		}
	}
	cout << ans;
	
	return 0;
} 
