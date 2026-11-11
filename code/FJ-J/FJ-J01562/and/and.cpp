#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int T;
const int N = 2e5;
int n, m;
int cs[31];

void solve() {
	cin >> n >> m;
	vector<vector<long long> > wsnums(31);
	for(int i=1; i<=n; i++) {
		long long a;
		cin >> a;
		long long aa = a;
		int sum=0;
		while(aa >= 1) {
			int t = aa % 2;
			if(t) {
				wsnums[sum].push_back(a);
			}
			aa/=2;
			++sum;
		}
	}
//	for(int i=0; i<=5; i++) {
//		cout << i << "/" << wsnums[i].size() << ": ";
//		sort(wsnums[i].begin(), wsnums[i].end(), greater<int>());
//		for(int j=0; j<wsnums[i].size(); j++) {
//			cout << wsnums[i][j] << " ";
//		}
//		cout << endl;
//	}
	int ans=0;
	for(int i=30; i>=0; i--) {
		if(wsnums[i].size() >= m) {
//			cout << "choice: " << i<<endl;
			sort(wsnums[i].begin(), wsnums[i].end(), greater<int>());
			for(int j=0; j<m; j++) {
				if(j == 0) {
					ans = wsnums[i][j];
				} else {
					ans &= wsnums[i][j];
				}
			}
			break;
		}
	}
	cout << ans << endl;
	return;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	IOS;
	T = 1;
//	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}

