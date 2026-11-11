#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
bool a[30][N];
bool out[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		for(int j = 0; j < 30; j++) a[j][i] = (t >> j) & 1;
	}
	
	int ans = 0;
	for(int i = 29; i >= 0; i--) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) if(a[i][j] && !out[j]) cnt++;
		if(cnt >= m && cnt >= 2) {
			ans += (1 << i);
			for(int j = 1; j <= n; j++) if(!a[i][j]) out[j] = true; 
		}
	}
	
	cout << ans << '\n';
	return 0;
}
