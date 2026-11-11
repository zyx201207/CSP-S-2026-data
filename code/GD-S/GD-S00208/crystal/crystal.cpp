#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m;
int a[500005];
int ans;
int ma = -1e12 -12;

int cmp(int x, int y) {
	return x < y;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+1+n, cmp);
	for(int i=2; i<=n; i++) {
		int t = m;
		ans = 1;
		for(int j=i-1; j>=1; j--) {
			if(t < a[i] - a[j]) break;
			t -= (a[i] - a[j]);
			ans++;
		}
		ma = max(ma, ans);
//		cout << ma << endl;
	}
	cout << ma;
}
