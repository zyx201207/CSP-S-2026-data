#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main (){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort (a, a + n);
	if (m == 1){
		cout << a[n - 1];
	}
	if(m == 2){
		int ans = 0;
		for (int i = 1; i < n - 1; ++ i){
			for (int j = 0; j < n; ++ j){
				ans = max(ans, (a[i] & a[j]));
				cout << ans << " " << a[i] << " " << a[j] << endl;
			}
		}
		cout << ans;
		return 0;
	}
	if (m == n){
		int s = a[0];
		for (int i = 1; i < n; ++ i){
			s &= a[i];
		}
		cout << s << endl;
		return 0;
	}
}
