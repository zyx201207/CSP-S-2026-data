#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
// 考虑高精度

const int INF = 0x3f3f3f;
const int N = 5e5+5;

int n,m,a[N];
long long pre[N];

void solve() {
	cin >> n >> m;
	for(int i=1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i <= n; i++) {
		pre[i] = pre[i-1]+a[i];
	}
	
	int ans = 0;
	for(int i=1; i <= n; i++) {
		if((pre[i]+m)/i >= a[i]) {
			ans = i;
		}
		else break;
	}
	cout << ans << endl;
	return;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int T=1;
//  cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}