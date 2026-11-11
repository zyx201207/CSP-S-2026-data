#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 5e5 + 5;

int n, ans = 1;
ll m, a[N], sum[N];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++) {
		int l = 0, r = i;
		while(l + 1 < r) {
			int mid = ((l + r) >> 1);
			if(a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans << endl;
} 
//rp++
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int T = 1;
//	cin >> T;
	while(T--) solve();
	
	return 0; 
}
