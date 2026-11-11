#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
constexpr int N = 500005;
int n;
ll m;
ll a[N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    a[0] = a[1];
    int p = 1, res = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i - p) * (a[i] - a[i - 1]);
        while (sum > m) {
            sum -= a[i] - a[p++];
        }
        res = max(res, i - p + 1);
    }
    cout << res << '\n';
    return 0;
}