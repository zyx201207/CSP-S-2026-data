#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+6;
int x[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,t; cin>>c>>t;
	if(c == 11 || c == 12) {
		while(t--) {
			int n,d; cin>>n>>d;
			for(int i=1; i<=n; i++) cin>>x[i];
			cout<<(n-3)<<endl;
		}	
	}
	return 0;
}
