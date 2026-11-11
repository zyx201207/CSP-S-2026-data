#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		vector<vector<int>>bian(n+1);
		for(int i=1; i<n; i++) {
			int a,b;
			cin >> a >> b;
			bian[a].push_back(b);
			bian[b].push_back(a);
		}
		if(k==2) {
			cout<<1<<endl;
			continue;
		}
		int maxn = INT_MIN;
		for(auto hx : bian) {
			int l = hx.size();
			maxn = max(maxn,l);
		}
		if(maxn >= k + 1) {
			cout<<2<<endl;
		} else if(maxn == 2) {
			cout<<k-1<<endl;
		} else {
			cout << k-maxn+1<<endl;
		}
	}
	return 0;
}
//
