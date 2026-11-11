#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long n,a[N],sum,ans;
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	long long mid = sum >> 1, m = 0;
	for(int i = 1, j = n; i <= j && m <= mid;) {
		if (c[i] != c[j]) {
			ans += min(a[i],a[j]);
		}
		if (a[i] == a[j]) {
			m += a[i];
			i ++;
			j --;
		}else if (a[i] > a[j]) {
			m += a[j];
			a[i] -= a[j];
			j --;
		}else {
			m += a[i];
			a[j] -= a[i];
			i ++;
		}
	}
	cout << ans;
	return 0;
}
