#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+6;
int u[N], v[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c,t; cin>>c>>t;
	while(t--) {
		int n,k; cin>>n>>k;
		for(int i=1; i<n; i++) cin>>u[i]>>v[i];
	}
	return 0;
} 
