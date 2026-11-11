#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500;
int n, m, a[N], tma, s[N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tma = max(a[i], tma);
    }
    if(m == 1) cout << tma;
    else if(m == 2) {
        int ma = -114514;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; i++) {
                ma = max(a[i] & a[j], ma);
            }
        }
        cout << ma;
    }
    else if(m == n) {
        sort(a + 1, a + n + 1, greater<int>());
        int ans = a[1];
        for(int i = 1; i <= n; i++) {
            ans = ans & a[i];
        }
        cout << ans;
    }
    return 0;
}
