#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>a[i];
	int k=d/(a[2]-a[1]);
	if(n==1||k<=1) cout<<0<<'\n';
	else cout<<max(0ll,n-k*2+1)<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
