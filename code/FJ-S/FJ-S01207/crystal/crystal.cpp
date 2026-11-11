#include<bits/stdc++.h>
using namespace std;
// constexpr int N = 5e5 + 9;
int n;
long long m, a[500009];
bool check(int ans){
	if(ans == 1){return true;}
	long long x = 0;
	for(int i=1; i<ans; i++){
		x += a[ans] - a[i];
	}
	for(int i=ans; i<=n; i++){
		if(x <= m){return true;}
		x -= a[i] - a[i-ans+1];
		if(i < n){
			x += (a[i+1] - a[i]) * (ans - 1);
		}
	}
	return false;
}
int l, r, mid;
int ans = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	l = 1;
	r = n;
	while(l <= r){
		mid = l + r >> 1;
		if(check(mid)){
			ans = max(ans, mid);
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

