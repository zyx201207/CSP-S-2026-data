#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int ans = -1;
vector<int> a;
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> permutation;
    for (int i = 1; i <= n - m; i++) {
        permutation.emplace_back(0);
    }
    for (int i = 1; i <= m; i++) {
        permutation.emplace_back(1);
    }
    do {
        int sum = -1;
        for (int i = 1; i <= n; i++) {
            if (permutation[i - 1]) {
                if (sum == -1) {
                    sum = a[i];
                } else {
                    sum &= a[i];
                }
            }
        }
        ans = max(ans, sum);
    } while (next_permutation(permutation.begin(), permutation.end()));
    cout << ans << "\n";
    return 0;
}
