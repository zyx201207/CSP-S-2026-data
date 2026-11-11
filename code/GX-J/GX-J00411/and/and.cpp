#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxx = INT_MIN, maxi = INT_MIN;
long long s;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        if(i == 1) s = a[i];
        s &= a[i];
    }
    if(m == 1) {
        cout << maxx;
        return 0;
    }
    if(m == n) {
        cout << s;
        return 0;
    }
    if(m == 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                maxi = max(maxi, a[i] & a[j]);
            }
        }
        cout << maxi;
        return 0;
    }
    sort(a + 1, a + n + 1);
    cout << a[n - m + 1];
    return 0;
}
