#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long n, m; 
long long a[N];
long long ans, sum;
long long l = 1, r = 2;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	while(l <= r && r <= n) {
		sum += (r - l) * (a[r] - a[r-1]);
		while(sum > m && l <= r) {
			sum -= (a[r] - a[l]);
			l++;
		}
		ans = max(ans, r - l + 1);
		r++;
	}
	cout << ans << '\n';
	return 0;
} 
