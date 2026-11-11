#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5+5;
ll n,m,a[N],ans,h[N];

ll lf(ll x){
	ll l = 0,r = x;
	while (l+1 < r){
		ll mid = (l+r)>>1;
		if (mid*a[x]-h[x-1]+h[x-mid-1] <= m) l = mid;
		else r = mid;
	}
	return l;
}

void solve(){
	for (ll i = 1;i <= n;i++) ans = max(ans,lf(i)+1);
	cout<<ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (ll i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (ll i = 1;i <= n;i++) h[i] = h[i-1]+a[i];
	solve();
	return 0;
} 
