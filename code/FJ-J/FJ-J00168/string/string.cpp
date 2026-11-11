#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n = 0;
long long a[N];
char cc[110];
string c[N];
long long sum = 0;
long long ans = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		scanf("%s", cc);
		c[i] = cc;
		sum += a[i];
	}
	long long l = 1, r = n, nl = 1, nr = sum;
	while(nl <= nr) {
		if (c[l][0] != c[r][0]) {
			ans += min(a[l], a[r]);
		}
		nl += min(a[l], a[r]);
		nr -= min(a[l], a[r]);
		long long tal = a[l];
		long long tar = a[r];
		a[l] -= min(tal, tar);
		a[r] -= min(tal, tar);
		if (a[l] == 0) {
			l++;
		}
		if (a[r] == 0) {
			r--;
		}
	}
	cout << ans;
	return 0;
}
