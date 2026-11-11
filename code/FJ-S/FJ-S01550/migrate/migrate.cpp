#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,d;cin>>n>>d;
	vector<int> x(n+1);
	for (int i=1;i<=n;i++) cin>>x[i];
//	cerr<<n<<endl;
	int delt=x[2]-x[1];
	if (d<delt*2){
		cout<<0<<endl;
		return;
	}
	int k=d/delt;
	int ans=0;
	for (int i=1;i<n-k;i++) ans+=n-i-k;
	cout<<ans<<endl;
//	cout<<0<<endl;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _=1;
	int c;cin>>c;
	cin>>_;
	while (_--) solve();
	return 0;
}

