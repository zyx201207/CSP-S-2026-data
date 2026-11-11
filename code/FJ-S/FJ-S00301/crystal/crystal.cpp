#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5 + 100;
int n, m, l = 1e18, r = -1e18, ans, a[N];
int check(int x){
	
}
signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ans = l;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	sort(a + 1, a + n + 1);
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(check(mid)){ 
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}

