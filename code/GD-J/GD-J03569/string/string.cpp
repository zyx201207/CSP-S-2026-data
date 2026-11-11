#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans, l, r;
long long a[200005], o[200005];
char c[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		o[i] = a[i];
	}
	l = 1, r = n;
	while(true){
		if (l >= r) break;
		if (c[l] != c[r]){
			if (o[l] < o[r]){
				ans += o[l];
				o[r] -= o[l];
				o[l] = 0;
			}else{
				ans += o[r];
				o[l] -= o[r];
				o[r] = 0;
			}
		}else{
			if (o[l] < o[r]){
				o[r] -= o[l];
				o[l] = 0;
			}else{
				o[l] -= o[r];
				o[r] = 0;
			}
		}
		if (o[l] == 0){
			l++;
		}
		if (o[r] == 0){
			r--;
		}
	}
	cout << ans;
	return 0;
} 
