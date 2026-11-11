#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, a[N], m;
signed main() {  cin.tie(nullptr) -> ios::sync_with_stdio(0);
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    sort(a + 1, a + n + 1);
    int l = 1, sum = 0;
    for (int r = 1; r <= n; r++) {
        int mx = a[r]; sum += a[r];
        while (mx * (r - l + 1) - sum > m && l < r) sum -= a[l++];
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall -Wextra -fsanitize=undefined,address && ./crystal

5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4
*/