#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main (){
	preopen("and.in", "r", stdin);
	preopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	if (n > 20 && n <= 2000){
		if (m == 1){
			cout << a[n];
		}else if (m == 2){
			long long ans1 = a[n] & a[n-1], ans2 = a[n-1] & a[n-2], ans3 = a[n-2] & a[n-3];
			long long ans = max(ans2, ans3);
			ans = max(ans, ans1);
			cout << ans;
		}else {
			long long ans = a[n];
			for (int i = n-1; i >= 1; i--){
				ans &= a[i];
			}
			cout << ans;
		}
		return 0;
	}
	long long ans1 = a[n], ans2 = a[n-1], ans3 = a[n-2], ans4 = a[n-3];
	for (int i = 1; i <= m; i++){
		ans1 &= a[n-i+1];
		ans2 &= a[n-i];
		ans3 &= a[n-i-1];
		ans4 &= a[n-i-2];
	}
	long long ans = max(ans4, ans3);
	ans = max(ans, ans2);
	ans = max(ans, ans1);
	cout << ans;
}
