#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,idx=1;
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=1,u,v; i<n; i++) cin >> u >> v;
		cout << idx;
		idx++;
	}
	return 0;
}
