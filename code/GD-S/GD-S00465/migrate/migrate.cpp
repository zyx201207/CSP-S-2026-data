#include <bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N];
void solve() {
	cin >> n >> d;
	for(int i=1;i<=n;++i) cin >> a[i];
	cout << n-2*d << '\n';
}
signed main() {
	IOS
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--) {
		solve();
	}
	return 0;
}

