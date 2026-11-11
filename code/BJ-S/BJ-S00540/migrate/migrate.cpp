// 40 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;

struct Solver1 {
    void main()
    {
        int n;
        i64 d;
        cin >> n >> d;

        vector<i64> x(n);
        for (i64& y : x)
            cin >> y;

        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, INF);
            vector<i64> cnt(n);
            dist[i] = 0;
            cnt[i] = 1;

            for (int j = i + 1; j < n; ++j) {
                for (int k = j - 1; k >= i && x[j] - x[k] <= d; --k) {
                    if (dist[j] > dist[k] + 1) {
                        dist[j] = dist[k] + 1;
                        cnt[j] = cnt[k];
                    } else if (dist[j] == dist[k] + 1 && cnt[j] <= 2)
                        cnt[j] += cnt[k];
                }
                ans += cnt[j] == 2;
            }
        }

        cout << ans << '\n';
    }
};

// A
struct Solver2 {
    void main()
    {
        int n;
        i64 d;
        cin >> n >> d;

        vector<i64> x(n);
        for (i64& y : x)
            cin >> y;

        i64 step = d / (x[1] - x[0]);
        cout << (n == 1 || step <= 1 ? 0 : max(0LL, n - (step << 1) + 1)) << '\n';
    }
};

// B
struct Solver3 {
    void main()
    {
        int n;
        i64 d;
        cin >> n >> d;

        vector<i64> x(n);
        for (i64& y : x)
            cin >> y;

        auto check = [&](int i, int j) {
            return x[j] - x[i] > d && upper_bound(x.begin(), x.end(), x[i] + d) - lower_bound(x.begin(), x.end(), x[j] - d) == 2;
        };

        int ans = 0;
        for (int l = 0; l < n; ++l) {
            int mid = upper_bound(x.begin(), x.end(), x[l] + d) - x.begin() - 1;
            if (mid > 0)
                ans += check(l, upper_bound(x.begin(), x.end(), x[mid - 1] + d) - x.begin() - 1);
        }

        cout << ans << '\n';
    }
};

struct Solver4 {
    i64 d;

    int solve(auto lo, auto hi)
    {
        auto check = [&](int i, int j) {
            return *(lo + j) - *(lo + i) > d && upper_bound(lo, hi, *(lo + i) + d) - lower_bound(lo, hi, *(lo + j) - d) == 2;
        };

        int ans = 0, n = hi - lo;
        for (int l = 0; l < n; ++l) {
            int mid = upper_bound(lo, hi, *(lo + l) + d) - lo - 1;
            if (mid > 0)
                ans += check(l, upper_bound(lo, hi, *(lo + mid - 1) + d) - lo - 1);
        }

        return ans;
    }

    void main()
    {
        int n;
        cin >> n >> d;

        vector<i64> x(n);
        for (i64& y : x)
            cin >> y;

        i64 ans = 0;
        auto itr = x.begin();
        while (itr != x.end()) {
            auto nxt = lower_bound(itr, x.end(), *itr + (d << 1));
            ans += solve(itr, nxt);
            itr = nxt;
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;

    if (11 <= c && c <= 12) {
        while (t-- > 0)
            Solver2().main();
    } else if (13 <= c && c <= 14) {
        while (t-- > 0)
            Solver3().main();
    } else if (c <= 6) {
        while (t-- > 0)
            Solver1().main();
    } else {
        while (t-- > 0)
            Solver4().main();
    }
    
    cout << flush;
    return 0;
}