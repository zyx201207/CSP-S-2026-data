#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
char c[200005];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++) {
		cin >> a[i] >> c[i];
	}
	if(n == 1) {
		cout << 0;
		return 0;
	}
	unsigned long long ans = 0ULL;
	int l = 0 , r = n - 1;
	unsigned long long l1 = a[0] , l2 = a[n - 1];
	while(l < r) {
		if(l1 > l2) {
			if(c[r] != c[l]) {
				ans += l2;
			}
			l1 -= l2;
			r --;
			l2 = a[r];
		}else if(l1 < l2) {
			if(c[r] != c[l]) {
				ans += l1;
			}
			l2 -= l1;
			l ++;
			l1 = a[l];
		}else{
			if(c[r] != c[l]) {
				ans += l2;
			}
			if(l == r - 1) {
				break;
			}
			l ++;
			r --;
			l2 = a[r];
			l1 = a[l];
		}
	}
	cout << ans;
	return 0;
}
