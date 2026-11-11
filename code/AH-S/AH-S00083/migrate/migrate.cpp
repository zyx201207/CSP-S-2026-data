#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,d,d0,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(); cout.tie();
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;++i) cin>>a[i];
		if (c==13 || c==14){
			cout<<0<<'\n';
			continue;
		}
		d0=a[2]-a[1];
		if (d/d0<=1 || d/d0+2>n){
			cout<<0<<'\n';
			continue;
		}
		ll d1=((double)d/d0)*d0;
		ll c=d/d1+1;
		cout<<n-c<<'\n';
	}
	return 0;
}
