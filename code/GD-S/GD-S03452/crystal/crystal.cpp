#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll n, m, ans = 0;
ll a[N], s[N];

ll search(ll x, ll mn, ll mx){
	ll l = mn, r = mx;
	while(l<=r){
		ll mid = (l+r)/2;
		if(a[x]*(x-mid+1)-s[x]+s[mid-1]>m){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	return l;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1, a+1+n);
	for(int i=1;i<=n;++i) s[i] = s[i-1]+a[i];
	for(int i=1;i<=n;++i) ans = max(ans, i-search(i, 1, i)+1);
	cout << ans;

	return 0;
}
