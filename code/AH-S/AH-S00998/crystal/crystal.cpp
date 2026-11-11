#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5 + 5;
int n, ans; ll m;
ll a[N], sum[N];

bool check(int l, int r) {
	return (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) <= m;
}

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while(l < r) {
			int mid = l + r >> 1;
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}

