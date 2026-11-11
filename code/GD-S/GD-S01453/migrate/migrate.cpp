#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		for(int i=1; i<=n; i++) {
			if(3*(x[i+1]-x[i])<d) {
				cout<<0;
				break;
			}
		}
		int ans=n-3;
		cout<<ans<<endl;
	}


	return 0;
}
