#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]) {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n{}; ll m{};
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 0; int l = 0, r = 0, ans = 0;
    while (r < n) {
        if (res <= m) {
            r++, res += (a[r] - a[r - 1]) * (r - l);
        } else {
            l++, res -= (a[r] - a[l - 1]);
        }
        ans = max(ans, (res <= m) * (r - l + 1));
    }
    cout << ans << endl;
    return 0;
}