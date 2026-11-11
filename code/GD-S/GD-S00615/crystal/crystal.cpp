#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long n, m;
long long sum[500010];
//long long d[500010];
//long long ds[500010];
//bool check(long long x){
//	long long s = (sum[x] + m) / x;
//	if(a[x] <= s) return true;
//	else return false;
//}
bool check(long long x){
	for(long long q = 1;q <= n && q+x-1 <= n;q++){
		long long s = (sum[q+x-1] - sum[q-1] + m) / x;
		if(a[q+x-1] <= s) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i-1] + a[i];
//		d[i] = a[i] - a[i-1];
//		ds[i] = d[i] + ds[i-1];
	} 
	long long l = 1, r = n;
	int ans = 0;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
} 
