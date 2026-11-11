#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
const int N = 2e6 + 3;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) {
			int u, v;
			cin >> u >> v;
		}
		n /= 2;
		int ans = 0x3f3f3f3f;
		int k1 = k / 2, k2 = (k % 2) ? k / 2 + 1 : k / 2;
		for(int i = 1; i <= n; ++i) {
			int j = i + k1;
			int len = n - j + 1;
			if(j > n) break;
			ans = min(ans, max({i - 1, (len - k2) % 2 ? ((len - k2) / 2 + 1) : (len - k2) / 2}));
		}
		cout << ans << '\n';
	}
	
	return 0;
} 
