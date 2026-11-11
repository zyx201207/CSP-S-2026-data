#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int, int>
const int N = 1000010;
const int inf = 1e18;
using namespace std;
int a[N], b[N];
char ca[N], cb[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s = 0;
	cin >> n;
	For(i, 1, n) {
		cin >> a[i] >> ca[i];
		s += a[i]; 
	}
	Rof(i, n, 1) {
		b[n - i + 1] = a[i];
		cb[n - i + 1] = ca[i];
	}
	int la = 1, lb = 1, sa = a[1], sb = b[1], ans = 0, cnt = 0; 
	while (cnt < s / 2) {
		if(ca[la] != cb[lb]) {
			if(sa >= sb) {
				ans += sb;
				cnt += sb;
				lb ++;
				sa -= sb;
				sb = b[lb];
			} else {
				ans += sa;
				cnt += sa;
				la ++;
				sb -= sa;
				sa = a[la];
			}
		} else {
			if(sa >= sb) {
				cnt += sb;
				lb ++;
				sa -= sb;
				sb = b[lb];
			} else {
				cnt += sa;
				la ++;
				sb -= sa;
				sa = a[la];
			}
		}
		if(sa == 0) {
			la ++;
			sa = a[la];
		}
		if(sb == 0) {
			lb ++;
			sb = b[lb];
		}
	}
	cout << ans;
	return 0;
}
