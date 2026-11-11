#include <bits/stdc++.h>

typedef long long ll;

const int N = 2e6 + 10;

int n, dis[N], cnt[N];
ll x[N], d, ans;

void solve() {
    std::cin >> n >> d;
    ans = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> x[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
            dis[i] = INT_MAX / 2;
        }

        dis[i] = 0;
        cnt[i] = 1;
        std::queue<int> q;
        q.emplace(i);

        while (q.size()) {
            int num = q.front();
            q.pop();

            if (cnt[num] == 2) {
                ++ans;
            }

            for (int i = num + 1; i <= n && (x[i] - x[num]) <= d; i++) {
                if (dis[i] > dis[num] + 1) {
                    dis[i] = dis[num] + 1;
                    cnt[i] = cnt[num];
                    q.emplace(i);
                }
                else if (dis[i] == dis[num] + 1) {
                    cnt[i] += cnt[num];
                    cnt[i] = std::min(cnt[i], 3);
                }
            }
        }
    }

    std::cout << ans << '\n';
}

FILE *IG;

int main() {
    IG = freopen("migrate.in", "r", stdin);
    IG = freopen("migrate.out", "w", stdout);
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int c, t;
    std::cin >> c >> t;

    while (t--) {
        solve();
    }

    return 0;
}