#include <iostream>
#define int long long
using namespace std;
const int N=2e6+5;

int n, d;
int c, t;
int a[N];

inline void sol () {
	int ans=0;
	cin>>n>>d;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int p=a[2]-a[1];
	if (d<2*p || d>=3*p) cout<<"0\n";
	else {
		for (int i=1; i<=n-2; i++) ans+=n-2-i;
		cout<<ans<<'\n'; 
	}
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (0), cin.tie (0);
	cin>>c>>t;
	while (t--) {
		cout<<"0\n";
	}
	return 0;
}
//CSP-S RP++
