#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long a[N];
long long n;
long long m;
long long sum1[N], sum[N];
bool check(long long x){
	for(long long i = x;i <= n;i++){
		if(sum[i - x + 1] - sum[i] - (a[n] - a[i]) * (x - 1) <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if(n <= 5000){
		long long maxn = INT_MIN;
		for(long long i = 1;i <= n;i++){
			long long ans = 0;
			for(long long j = i, cnt = 0;j >= 1;j--){
				if(cnt + a[i] - a[j] <= m){
					cnt += a[i] - a[j];
					ans++;
				}
				else break;
			}
			maxn = max(maxn, ans);
		}
		cout << maxn;
		return 0;
	}
	sum1[n] = 0;
	sum[n] = 0;
	for(long long i = n - 1;i >= 1;i--){
		sum1[i] = sum1[i + 1] + a[i + 1] - a[i];
		sum[i] = sum[i + 1] + sum1[i];
	}
	long long l = 1, r = n, ans = 0;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
