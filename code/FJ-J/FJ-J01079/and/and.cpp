#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

int n, m;
ll a[MAXN], b[MAXN];
int cnt, tot;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	tot = n;
	for (int i = 29; i >= 0; i --) {
		ll tmp = 1 << i;
		cnt = 0;
		for (int j = 1; j <= tot; j ++) {
			if (a[j] & tmp) {
				b[++ cnt] = a[j];
			}
		}
		
		if (cnt >= m) {
			for (int j = 1; j <= cnt; j ++) {
				a[j] = b[j];
			}
			tot = cnt;
		} 
	}
	
	ll ans = a[1];
	for (int i = 2; i <= tot; i ++) {
		ans &= a[i];
	}
	
	cout << ans << '\n';
	return 0;
}
