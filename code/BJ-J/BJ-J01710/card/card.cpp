#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int a[N], b[N];
int ans[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int x = 1; x <= n; x++) {
		memset(b, 0, sizeof(b));
		for(int i = x; i <= n; i++) {
			if(b[a[i]] == 0){
				b[a[i]]++;
			}else {
				memset(b, 0, sizeof(b));
				b[a[i]]++;
			}
		}
		for(int k = 1; k <= m; k++) {
			if(b[k] != 0) {
				ans[k]++;
			}
		}
	}
	cout << ans[1];
	for(int i = 2; i <= m; i++) {
		cout << " " << ans[i];
	}
	cout << '\n';
	return 0;
}
