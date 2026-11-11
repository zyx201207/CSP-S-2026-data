#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans;
long long m, a[N], s[N];
inline bool check(int x) {
	for(int i=x;i<=n;i++) {
		if(a[i]*x - s[i] + s[i-x] <= m) {
			return true;
		}
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	int l = 1, r = n, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout<<ans;
	return 0;
}
