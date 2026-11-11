#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
long long ans;
long long f(int pos, int x) {
    if (x == 1) {
        return a[pos];
    }
    for (int i = pos; i <= n; i++) {
        ans = max(ans, (a[i] & f(i + 1, x - 1)));
    }
    return ans;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);
    ans = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << f(1, m);
    return 0;
}