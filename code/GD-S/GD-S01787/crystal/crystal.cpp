#include<bits/stdc++.h>
using namespace std;
#define vec std::vector
#define ll long long
#define i128 __int128
#define endl "\n"
ll read(){
	ll num = 0; int f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = (num << 1) + (num << 3) + (c ^ 48);
		c = getchar();
	}
	return num * f;
}
constexpr int N = 5e5 + 5;
int n; ll m;
ll a[N], sum[N];
bool chk(int s, int e) {
	int len = e - s + 1;
	return (1ll * len * a[e] - (sum[e] - sum[s - 1])) <= m;
}
int main(){
//	freopen("1.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	stable_sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i, res = r;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (chk(mid, i)) {
				res = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}
