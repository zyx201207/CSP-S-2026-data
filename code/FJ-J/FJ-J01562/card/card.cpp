#include<iostream>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int T;
const int N = 5e5+5, M = 3e5+5;
int n, m;
int a[N];
int alive[M], ans[M];

void solve() {
	cin >> n >> m;
	bool f = true;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i] < a[i-1]) {
			f = false;
		}
	}
	if(f) {
		for(int i=1; i<=n; i++) {
			ans[a[i]]++;
		}
		for(int j=1; j<=m; j++) {
			ans[j] += ans[j-1];
			cout << ans[j] << ((j != m) ? " " : endl);
		}
	} else {
		for(int op=1; op<=n; op++) {
			for(int j=1; j<=m; j++) {
				alive[j] = 0;
			}
			for(int i=op; i<=n; i++) {
				if(alive[a[i]] != 0) {
					for(int j=1; j<=m; j++) {
						if(alive[j] > alive[a[i]]) {
							alive[j] = 0;
						}
					}
				}
				alive[a[i]] = i;
			}
			for(int j=1; j<=m; j++) {
				if(alive[j] != 0) {
					ans[a[alive[j]]]++;
				}
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout << ans[i] << ((i != m) ? " " : endl);
	}
	return;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	IOS;
	T = 1;
//	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}

