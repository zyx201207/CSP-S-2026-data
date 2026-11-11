#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], ans = 0;
long long nowwrong = 0;
long long check(long long n){
	long long cnt = 1;
	long long len = m;
	for(int i = n - 1; i >= 1; i--){
		if( len >= 0){
			cnt++;
			len = len + a[i] - a[n];
		}
		else{
			nowwrong = i;
			break;
		}
	}
	
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long l = 0, r = n;
	while(l <= r){
		long long mid = (l + r - 1) >> 1;
		nowwrong = 0;
		if(ans < check(mid)){
			ans = mid - nowwrong;
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout << ans;
	return 0;
}
