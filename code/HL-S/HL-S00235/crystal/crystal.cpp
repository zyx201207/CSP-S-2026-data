#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

constexpr int maxn = 5e5 + 5;

using ll = long long;

ll n, m, a[maxn], now, ans, presum[maxn];
deque<int> dq;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) presum[i] = presum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        while (dq.size() && now > m) now -= a[dq.back()] - a[dq.front()], dq.pop_front();
        if (now <= m) ans = max(ans, (ll)dq.size());
        dq.push_back(i);
        now += (a[i] - a[i - 1]) * (dq.size() - 1);
    }
    cout << ans;
    return 0;
}
