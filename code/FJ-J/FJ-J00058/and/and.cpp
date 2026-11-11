#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, m, ans, a[N];
bool banned[N];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 30; i >= 0; i--) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(banned[j]) continue;
			if((a[j] >> i) & 1) cnt++;
		}
		if(cnt < m) continue;
		for(int j = 1; j <= n; j++) {
			if(banned[j]) continue;
			if(!((a[j] >> i) & 1)) banned[j] = true;
		} 
		ans += (1 << i);
	}
	cout << ans << endl;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T = 1;
//	cin >> T;
	while(T--) solve();

	return 0;
}

