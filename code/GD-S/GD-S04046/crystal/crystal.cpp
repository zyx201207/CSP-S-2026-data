#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], sum[500005], ans = 1, l;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
	} 
	l = 1;
	for (int r = 2; r <= n; r++){
		while((r-l+1) * a[r] - (sum[r] - sum[l-1]) > m){
			l++;
		}
		ans = max(ans, r-l+1);
	}
	cout << ans;
	return 0;
}
