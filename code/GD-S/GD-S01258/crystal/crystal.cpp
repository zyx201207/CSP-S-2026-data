#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N] , ma = 1;
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out", "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for (int i = 1; i <= n; i++) {
		int k = i , mm = m , cnt = 0;
		while (k > 0 && a[i] - a[k] <= mm && cnt <= i) {
			mm -= a[i] - a[k];
			cnt++;
			k--;
		}
		ma = max(ma , cnt);
	}
	cout << ma;
	return 0;
}
