// GZ-J00545 杜泽煊 
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<char> c(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
	}
	bool flag = n % 2 == 1;
	bool yanchi = 0; 
	int ans = 0;
	for(int i = 1, j = n; i <= n, j >= 1; ) {
		if((i == j && flag) || yanchi) { // 到中心了
			cout << ans << "\n";
			exit(0);
		}
		if(j - i == 1 && !flag) {
			yanchi = 1;
		}
		
		if(c[i] == c[j]) {
			if(a[i] > a[j]) {
				a[i] -= a[j];
				j --;
			} else if(a[i] < a[j]) {
				a[j] -= a[i];
				i ++;
			} else {
				i ++;
				j --;
			}
		} else {
			if(a[i] > a[j]) {
				a[i] -= a[j];
				ans += a[j];
				j --;
			} else if(a[i] < a[j]) {
				a[j] -= a[i];
				ans += a[i];
				i ++;
			} else {
				//cout << 1  <<":" << a[i] << " " << a[j]<<"\n";
				ans += a[i];
				i ++;
				j --;
				
				
			}
		}
	}
	return 0;
}

