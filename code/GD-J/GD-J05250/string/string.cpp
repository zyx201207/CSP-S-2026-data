#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n;
long long a[N];
char c[N];
long long s[N] , ans = 0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> c[i];
		s[i] = s[i-1] + a[i];
	}
	long long L = s[n];
	long long l = 1 , r = L;
	int pl = 1 , pr = n;
	L /= 2;
	while(l < L+1) {
		int k = min(s[pl]-l+1 , r-s[pr-1]);
		if(l + k >= L+1) {
			k = L - l + 1;
		}
			if(c[pl] != c[pr]) {
			ans += k;
		}
		l += k;
		r -= k;
		if(l > s[pl]) pl++;
		if(r <= s[pr-1]) pr--;
	}
	cout << ans;
	return 0;
}
