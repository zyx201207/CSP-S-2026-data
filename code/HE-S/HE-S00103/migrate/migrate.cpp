#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+66;
int a[N],n,c,t,d;
bool p;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		if(d>=a[n]-a[1]) cout<<0<<'\n';
		else {
			
			if((a[2]-a[1]==a[3]-a[2])&&n>4&&d>(a[n]-a[1])/2) cout<<(n+1)/2<<'\n';
			else if(n==4) cout<<1;
			else cout<<0<<'\n';
		}
	}
	return 0;
}
/*

*/
