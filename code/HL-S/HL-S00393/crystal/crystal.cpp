#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const long long M = 1e18;
int n;
long long m;
int ans;
int a[N], s[N], d[N];
long long mi = M, ma = -M;
long long f[M];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    s[1] = 0;
    for(int i = 2; i <= n; i++) {
        s[i] = a[i] - a[i-1];
    }
    for(int i = 1; i <= n; i++) {
        d[i] = d[i-1] + s[i] * (i - 1);
    }
	long long r = n;
    for(int l = 1; l <= r; l++) {
        for(; r >= l; r--) {
        	long long cost = d[r] - d[l];
        	f[cost] = r - l;
		}
    }
    for(long long i = 1; i <= m; i++) {
    	ma = max(ma, f[i]);
	}
	cout << ma;
    return 0;
}
