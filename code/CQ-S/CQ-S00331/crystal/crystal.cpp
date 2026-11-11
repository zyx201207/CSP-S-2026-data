#include<bits/stdc++.h>
#define qaq ios::sync_with_stdio(0), cin.tie(0)
#define lb(x) (x&(-x))
#define PII pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(x) cout << #x << "=" << x << " "
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N],m,s[N];
int n;
inline int solve(int i) {
	int l = -1, r = i, ans = i;
	while(r-l>1) {
		int mid = (l+r)>>1;
		ll o = i - mid;
		if(o * a[i] - s[i] + s[mid] <= m) r = mid, ans = mid;
		else l = mid;
	}
	return ans;
}
int main() {
	qaq;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+1+n);
	rep(i, 1, n) s[i] = s[i-1] + a[i];
	int ans = 0;
	rep(i, 1, n) ans = max(ans, i - solve(i));
	cout << ans << "\n";
	return 0;
}
