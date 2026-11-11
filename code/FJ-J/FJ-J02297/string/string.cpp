#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	const int MAXN = 2000005;
	long long l = 1,r,n,a[MAXN],ans = 0;
	char c[MAXN];
	
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		cin >> c[i];
		r += a[i];
	}
	
	while(l < r) {
		if(a[l] == a[r]) {
			if(c[l] != c[r]) 
				ans += a[l];
			l++;
			r--;
		}
		if(a[l] != a[r]) {
			while(a[l] > a[r]) {
				if(c[l] != c[r]) 
					ans += a[r];
					a[l] -= a[r];
					r--;
			}
			while(a[l] < a[r]) {
				if(c[l] != c[r]) 
					ans += a[l];
					a[r] -= a[l];
					l++;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
} 
