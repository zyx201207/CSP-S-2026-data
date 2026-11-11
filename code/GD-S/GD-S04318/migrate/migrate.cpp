#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
const int N=2e6+5;
int a[N];
signed main() {
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		int diff=a[2]-a[1],ans=0;
		int r=d/diff,k=1,t=1;
		while(k*r+r-1<n) {
			ans+=(r-1)*n-(r-1)*k*r-r*(r-1)/2;
			k++;
		}
		while(n-(k*r+t)>=0) {
			ans+=n-(k*r+t);
			t++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
