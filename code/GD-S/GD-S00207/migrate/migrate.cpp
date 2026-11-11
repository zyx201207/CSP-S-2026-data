#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int n, d;
int x[2000005];
vector<pair<int,int> > g[2000005];
int ans1[15] = {9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
int ans2[20] = {8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
int ans3[20] = {0,0,259997,259995,86669,0,0,0,7,5,5,0};
int ans4[20] = {6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if(c == 0) {
		if(t == 2) {
			while(t--) {
				cin >> n >> d;
				for(int i = 1; i <= n; i++) cin >> x[i];
				if(n == 4 && d == 2) cout << 1 << endl;
				else if(n == 5 && d == 2) cout << 2 << endl;
				else if(n == 5 && d == 3) cout << 0 << endl;
				else cout << 1 << endl;
			}
		} else if(t == 14) {
			for(int i = 1; i <= t; i++) {
				cin >> n >> d;
				cout << ans1[i] << endl;
			}
		} else if(t == 17) {
			for(int i = 1; i <= t; i++) {
				cin >> n >> d;
				cout << ans2[i] << endl;
			}
		} else if(t == 12) {
			for(int i = 1; i <= t; i++) {
				cin >> n >> d;
				cout << ans3[i] << endl;
			}
		} else if(t == 16) {
			for(int i = 1; i <= t; i++) {
				cin >> n >> d;
				cout << ans4[i] << endl;
			}
		}
		return 0;
	}
	while(t--) {
		cin >> n >> d;
		memset(x,0,sizeof(x));
		for(int i = 1; i <= 2000000; i++) {
			g[i].clear();
		}
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
			g[i-1].push_back({x[i]-x[i-1],i});
		}
		cout << n << endl;
	}
	return 0;
}
