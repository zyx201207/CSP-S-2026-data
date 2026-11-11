#include<bits/stdc++.h>
using namespace std;
int n;
long long m, a[500003], b[500003], ans = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		b[i] = a[i] + b[i - 1];
	}
	long long l = 1, r = 2;
	while(r <= n){
		if(l == r){
			r++;
		}
		if(r > n) break;
		long long k = a[r] * (r - l) - b[r - 1] + b[l - 1];
		if(k <= m){
			if(r == n && ans > r - l + 1) break;
			ans = max(ans, r - l + 1);
			r++;
		}else{
			l++;
		}
	}
	cout << ans;
	return 0;
}
