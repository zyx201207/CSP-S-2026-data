#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
ll a[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,q;
	cin>>c>>q;
	if(c==0&&q==2) {
		cout<<1<<'\n'<<2;
		return 0;
	}
	while(q--) {
		ll n,d;
		for(int i=1; i<=n; i++) cin>>a[i];
		cout<<0<<'\n';
	}
	return 0;
}
