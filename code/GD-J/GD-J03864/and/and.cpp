#include <bits/stdc++.h>
using namespace std;

long long a[200005];


int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n <= 2000){
		if (m == 1){
			sort(a+1, a+1+n);
			cout << a[n];
			return 0;
		}
		else if(m == n){
			long long ans = a[1];
			for (int i = 2; i <= n; i++){
				ans &= a[i];
			}
			cout << ans;
			return 0;
		}
		else{
			long long ans = 0;
			for (int i = 1; i < n; i++){
				for (int j = i + 1; j <= n; j ++){
					ans = max(ans, a[i] & a[j]);
				}
			}
			cout << ans;
			return 0;
		}
	}
	else{
		cout << 0;
	}
	return 0;
}

