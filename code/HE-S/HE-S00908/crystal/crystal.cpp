#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
vector <int>b[N];
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx = 0, mn = 1e5;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {

        if (n == 1) {
            ans = 1;
            cout << ans;
            return 0;
        } else if(n == 2) {
            if (m >= (mx - mn)) {
                ans++;
            } else {
                ans = 1;
                cout << ans;
                return 0;
            }
        } else if(n == 3) {
            if (m >= (mx - mn)) {
                ans++;
            } else {
                ans = 1;
                cout << ans;
                return 0;
            }
        } else if(n == 4) {
            if (m >= (mx - mn)) {
                ans++;
            } else {
                ans = 1;
                cout << ans;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}
