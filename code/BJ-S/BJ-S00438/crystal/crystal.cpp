#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m;
ll a[500005];

bool check(ll mid){
	ll sum = 0;
	for(int i = 1;i < mid;i++){
		sum += a[mid] - a[i];
	}
	return sum <= m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	// freopen("crystal1.in","r",stdin);
	// freopen("crystal1.out","w",stdout);

	// freopen("crystal2.in","r",stdin);
	// freopen("crystal2.out","w",stdout);

	// freopen("crystal3.in","r",stdin);
	// freopen("crystal3.out","w",stdout);

	// freopen("crystal4.in","r",stdin);
	// freopen("crystal4.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	ll l = 1,r = n,ans;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(check(mid)) l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}