#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], ans = 1LL;
long long qz[500010];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >>n >>m;
	for(int i = 1; i <= n; i++) cin >>a[i];
	sort(a + 1, a + n + 1);
	long long i = 1LL, j = 1LL, wac = 0LL;
	while(i <= n && j <= n) {
		if(i == j) {
			j++;
			wac += (j - i) * (a[j] - a[j-1]);
		}
		while(wac <= m && j <= n) {
			ans = max(ans, j - i + 1LL);
			j++;
			wac += (j - i) * (a[j] - a[j-1]);
		}
		while(wac > m && i <= n) {
			wac -= (a[j] - a[i]);
			i++;
		}
	}
	cout <<ans;
}
