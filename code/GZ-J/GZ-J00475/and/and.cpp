//GZ-J00475 遵义市第四中学 卢语涵
#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[110000005];
long long ans, sum=1;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a+0, a+n);
	for(int k = 1; k <= n; k++) {
		ans = a[n-k];
		for(int i = n-k-1; i >= 0; i--) {
			if((ans & a[i]) == 0) continue;
			ans = (ans & a[i]);
			sum++;
			if(sum == m) {
				cout << ans;
				return 0;
			}
		}
		sum = 1;
	}
	return 0;
}
