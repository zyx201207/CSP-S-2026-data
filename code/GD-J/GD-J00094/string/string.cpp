#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	
	ll sum1 = a[1], sum2 = a[n];
	char c1 = c[1], c2 = c[n];
	ll ans = 0;
	for(int i = 1, j = n; i < j;) {
		int d = min(sum1, sum2);
		if(c1 != c2) ans += d;
		sum1 -= d;
		sum2 -= d;
		if(!sum1) sum1 += a[++i], c1 = c[i];
		if(!sum2) sum2 += a[--j], c2 = c[j];
	}
	
	cout << ans << '\n';
	return 0;
}
