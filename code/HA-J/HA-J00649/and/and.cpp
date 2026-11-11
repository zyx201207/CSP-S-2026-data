#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

int n, m, a[N], b[50];
bitset<N> mk;

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int k = 30; k >= 0; k --) {
		int cnt = 0;
		for (int i = 1; i <= n; i ++) if (!mk[i] && ((a[i] >> k) & 1) == 1) cnt ++;
		if (cnt >= m) 
		for (int i = 1; i <= n; i ++) if (!mk[i] && ((a[i] >> k) & 1) == 0) mk[i] = 1;
	}
	int ans = 0x7fffffff;
	for (int i = 1; i <= n; i ++) if(!mk[i]) ans &= a[i];
	cout << ans << "\n";
	
	return 0;
}

