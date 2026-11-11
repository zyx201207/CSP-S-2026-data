#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5E5+5;
LL n, m, a[N], mx;
bool check(int mid){
	int l = 1;
	LL res = 0;
	for (int i = 2; i <= n; i ++) {
		res+= (a[i]-a[i-1]) * (i-1);
		if (i > mid) res -= (a[i] - a[l++]);
		if (i >= mid && res <= m) return true;
	}
	return false;
}
int main() {
	freopen("crystal.in","r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	bool ok = true;
	for (int i = 1; i <= n; i ++) {
		if (a[i] != i) {
			ok = false;
			break;
		}
	}
	if (ok){
		LL s = 0,res;
		for (int i = 1; i <= n; i ++) {
			s += i;
			if (s>m) {
				res = i;
				break;
			}
		}
		cout << res;
	} else {
		int l = 1, r = n;
		while (l <= r){
			int mid = (l + r)>>1;
			if (check(mid))
				mx = mid, l= mid + 1;
			else r=mid-1;
		}
		cout <<mx;
	}
	return 0;
}
