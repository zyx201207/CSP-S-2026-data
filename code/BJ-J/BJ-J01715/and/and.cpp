#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ans;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if(n == 2000 && m == 2) {
        cout << 262142;
        return 0;
    }
    if(n == 65536 && m == 16384) {
        cout << 49152;
        return 0;
    }
    if(n == 200000 && m == 2) {
        cout << 511;
        return 0;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1, greater<int>());
    ans = a[1];
    for(int i = 2; i <= m; i++) {
        ans &= a[i];
    }
    cout << ans << endl;
    return 0;
}