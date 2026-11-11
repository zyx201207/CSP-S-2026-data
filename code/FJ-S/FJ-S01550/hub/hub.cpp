#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,k;cin>>n>>k;
//	cerr<<k<<endl;
	int m=(n-1)/2;
	int ans=0;
	if (k==1) ans=m;
	else{
		int p=(m+1)/2;
		ans=(p+1)/2;
		k-=2;
		cout<<max(0ll,ans-k/4)<<endl;
	}
//	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;cin>>c;
	int _=1;
	cin>>_;
	while (_--) solve();
	return 0;
}

