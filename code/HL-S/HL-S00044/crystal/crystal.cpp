#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 500010;
ll a[N],s[N];
int n;
ll m;

int check(int u) {
	int l = 1,r = u;
	int ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(s[u] - s[mid - 1] + m >= 1ll * (u - mid + 1) * a[u]) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return u - ans + 1;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;

	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for(int i = 2;i <= n;i++) {
		ans = max(ans,check(i));
	}
	cout << ans << '\n';
	return 0;
}
