#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long n;
long long a[N];
char c[N];
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(long long i = 1;i <= n;i++) cin >> a[i] >> c[i];
	long long l = 1, r = n;
	while(l < r) {
		if(a[l] < a[r]) {
			if(c[l] != c[r]) {
				ans += a[l];
			}
			a[r] -= a[l];
			l++;
		}else if(a[l] > a[r]){
			if(c[l] != c[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		}else {
			if(c[l] != c[r]) {
				ans += a[l]; 
			}
			l++, r--;
		}
	}
	cout << ans << '\n';
	return 0;
}
