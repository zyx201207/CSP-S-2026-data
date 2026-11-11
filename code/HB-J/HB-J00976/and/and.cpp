#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int ans = a[n - 1];
    for (int i = n - 1; i >= n - m; i--) {
        ans &= a[i];
    }
    cout << ans << endl;
    return 0;
}
