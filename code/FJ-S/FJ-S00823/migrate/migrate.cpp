#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d,a[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=2) {
			cout<<0<<'\n';continue;
		}
		
	}
	return 0;
}
