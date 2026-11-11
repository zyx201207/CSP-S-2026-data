#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
long long a[maxn], sum[maxn];
long long bins(long long k, long long nr){
	long long l = 1, r = nr;
	while(l < r){
		long long mid = (l + r) / 2;
		if((nr - mid) * a[nr] - sum[nr - 1] + sum[mid - 1] > k)l = mid + 1;
		else r = mid;
	}
	return l;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	sum[0] = 0;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	for(long long i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	} 
	long long maxans = 1;
	for(long long i = 1; i <= n; i++){
		maxans = max(i - bins(m, i) + 1, maxans);
	}
	cout << maxans;
	return 0;
}
