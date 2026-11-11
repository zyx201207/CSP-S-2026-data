#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N], ans = 0;
char c[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int L = 1, R = n;
	while(L < R) {
		if(c[L] == c[R]) {
			if(a[L] < a[R]) a[R] -= a[L], L++;
			else if(a[L] > a[R]) a[L] -= a[R], R--;
			else L++, R--;
		}
		else {
			ans += min(a[L], a[R]);
			if(a[L] < a[R]) a[R] -= a[L], L++;
			else if(a[L] > a[R]) a[L] -= a[R], R--;
			else L++, R--;
		}
		//cout << L << ' ' << a[L] << ' ' << R << ' ' << a[R];
		//cout << '\n';
	}
	cout << ans;
	return 0;
}
