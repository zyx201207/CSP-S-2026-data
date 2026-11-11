#include<bits/stdc++.h>
#define endl '\n' 
#define ll long long
using namespace std;
const int N=5e5+1;

ll n,m;
ll a[N];


int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll s = 0;
	ll l = 1;
	ll ans=0;
	for(ll i=2;i<=n;i++) {
		s += (a[i] - a[i-1]) * (i-l);
		while(s>m) {
			s -= a[i] - a[l++];
		}
		ans = max(ans, i-l+1);
	}
	cout<<ans;
	return 0;
}
