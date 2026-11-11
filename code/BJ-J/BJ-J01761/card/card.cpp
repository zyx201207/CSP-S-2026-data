#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef __int128 LL;
typedef unsigned long long ull;

ll a[500500];
ll ans[500500];

int main() {
    #ifndef LOCAL
        freopen("card.in", "r", stdin);
        freopen("card.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::deque<ll> dq;
        std::map<ll, ll> mp;
        for (int j = i; j <= n; j++) {
            if (mp[a[j]]) {
                while (dq.back() != a[j]) {
                    mp[dq.back()] = 0;
                    dq.pop_back();
                }
            }
            else {
                dq.push_back(a[j]);
                mp[a[j]] = 1;
            }
        }
        for (auto ele : mp) {
            if (ele.se == 1) {
                ans[ele.fi]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        std::cout << ans[i] << ' ';
    }
    return 0;
}