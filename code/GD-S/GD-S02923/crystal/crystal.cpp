#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

const int N = 5e5+10;
LL n, m, a[N], s[N], ans = -1e18;

bool check(LL k, LL i){
	return ( ( 1ll*(i-k)*a[i]-(s[i-1]-s[k-1]) ) <= m);
}

LL calc(int i){
	LL l = 1, r = i, mid, res=i;
	while(l <= r){
		mid = (l+r)/2;
		if (check(mid, i)){
			r = mid-1;
			res = mid;
		}
		else{
			l = mid+1;
		}
	}
	return (i-res+1);
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		s[i] = s[i-1] + a[i];
	}
	for (int i = 1; i <= n; i++){
		ans = max(ans, calc(i));
	}
	cout << ans;
	return 0;
}
