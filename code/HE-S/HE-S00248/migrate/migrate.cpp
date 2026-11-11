#include <bits/stdc++.h>
using namespace std;

ifstream fin("migrate.in");
ofstream fout("migrate.out");
#define cin fin
#define cout fout

typedef long long ll;
const ll N = 2e6+10;
ll a[N];

// 只考虑特殊性质A 
void solve() {
	ll n,d; cin>>n>>d;
	for (ll i=1; i<=n; ++i) {
		cin>>a[i];
	}
	ll cha = a[2]-a[1];
	if (d>=cha && d<2*cha) {
		cout<<0<<'\n';
		return;
	}
	ll max_blk = (d%cha==0)?d/cha:(d-(d%cha))/cha;
	ll ans=0;
	for (ll l=1; l<n-max_blk; ++l) {
		for (ll r=l+max_blk+1; r<=n; ++r) {
			ll count_blk = r-l;
			ll full_d_travle = count_blk/max_blk;
			ll rest = (count_blk%max_blk!=0) ? 1:0;
			if (full_d_travle==1 && rest==1) ++ans;
		}
	}
	cout<<ans<<'\n';
}

int main() {
	ll c,t; cin>>c>>t;
	while (t) {
		solve();
		t--;
	}
}
