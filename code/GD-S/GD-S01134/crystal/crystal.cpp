#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;

int n, ans = -1;
i64 m, a[N], sum[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int l = 1, r = 1; r <= n; r++) {
		while (a[r] * (r - l + 1) - sum[r] + sum[l - 1] > m) l++;
		ans = max (ans, r - l + 1);
	}
	cout << ans << '\n';
	
	return 0;
}

