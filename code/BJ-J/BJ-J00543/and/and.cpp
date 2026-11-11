#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int m;
    cin >> n >> m;
    int a[n];
    int y = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] >= 4) {
            y = 1;
        }
    }
    sort(a, a + n);
    int ans = 0;

    if(y == 0) {
        ans = a[n-1];
        for(int i = 1; i < m; ++i) {
            ans = ans & a[n-i-1];
        }
        cout << ans;
        return 0;
    }

    for(int i = 0; i <= n - m; ++i) {
        int x = a[n-i-1];
        for(int j = 1; j < m; ++j) {
            x = x & a[n-i-1-j];
        }
        if(x > ans) {
            ans = x;
        }
    }
    cout << ans;
    return 0;
}