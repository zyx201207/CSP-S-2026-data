//GZ-J00475 遵义市第四中学 卢语涵
#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long sum;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while(l <= n/2 && r >= n/2+1) {
		if(c[l] == c[r]) {
			if(a[l] >= a[r]) {
				a[l] -= a[r];
				if(a[l] == 0) {
					l++;
				}
				r--;
			} else {
				a[r] -= a[l];
				l++;
			}
		} else {
			if(a[l] >= a[r]) {
				a[l] -= a[r];
				if(a[l] == 0) {
					l++;
				}
				sum += a[r];
				r--;
			} else {
				a[r] -= a[l];
				sum += a[l];
				l++;
			}
		}
	}
	cout << sum;
	return 0;
}
