#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N]; 
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout); 
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, ans = 1; cin >> n >> m; 
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1, j = 1, sum = 0; i <= n; i++) {
        int k = i;
        while (k < n && a[k + 1] == a[i]) k++;
        sum += (i - j) * (a[i] - a[i - 1]);
        while (sum > m) sum -= a[i] - a[j++];
        ans = max(ans, k - j + 1); i = k; 
        // cerr << k << ' ' << j << '\n'; 
    }
    cout << ans << '\n'; 
    return 0; 
}