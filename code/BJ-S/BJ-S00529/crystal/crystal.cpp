#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n; ll m;
ll a[500010], pref[500010];

bool check(int k){
	for(int i = 1; i + k - 1 <= n; i ++){
		ll tot = pref[i + k - 1] - pref[i - 1];
		ll tgt = 1ll * k * a[i + k - 1];
		if(tgt - tot <= m) return true;
	}
	return false;
}

int main(){
#ifndef LOCAL_TEST
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) pref[i] = pref[i - 1] + a[i];
	int l = 1, r = n + 1;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
}