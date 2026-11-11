#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, ans = 0, lxc = 0;
int a[2000010];
char c[2000010];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while(l < r){
		if(c[l] != c[r]){
			lxc = 1;
		}
		if(a[l] < a[r]){
			a[r] = a[r] - a[l];
			a[l] = 0;
			ans = ans + a[r] * lxc;
			l++;
		} else if(a[l] > a[r]){
			a[l] = a[l] - a[r];
			a[r] = 0;
			ans = ans + a[l] * lxc;
			r--;
		} else {
			ans = ans + a[l] * lxc;
			a[l] = 0;
			a[l] = 0;
			l++;
			r--;
		}
		lxc = 0;
	}
	cout << ans << endl; 
	return 0;
}
