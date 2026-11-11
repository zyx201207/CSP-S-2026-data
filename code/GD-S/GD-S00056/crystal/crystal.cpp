#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int n;
long long m, a[N], sum[N];
bool check(int k){
	for(int i = k; i <= n; i++){
		if(1ll*k*a[i]-(sum[i]-sum[i-k]) <= m) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];
	int l = 1, r = n+1;
	while(l < r){
		int mid = l+((r-l)>>1);
		if(check(mid)) l = mid+1;
		else r = mid;
	}
	cout << l-1;
	return 0;
} 
