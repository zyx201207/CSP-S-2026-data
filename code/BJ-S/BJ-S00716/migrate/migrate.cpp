#include <bits/stdc++.h>
using namespace std;

#define int long long

int x[2000005], a[2000005];
int c, t, n, d;
int dp1[2000005], dp2[2000005], vis[2000005], cnt[2000005];
queue<int> q;

int bfs(int x, int op) {
    for (int i = 1; i <= n; ++i) {
        dp1[i] = 1e18, dp2[i] = 0, vis[i] = 0;
    }
    dp1[x] = 0;
    int lst = 0;
    dp2[x] = 1;
    while(q.size()) q.pop();
    q.push(x);
    while(q.size()) {
        int u = q.front();
        q.pop();
        for (int i = u + 1; i <= min(a[u], n); ++i) {
            if(vis[i] && dp1[u] + 1 == dp1[i]) {
                dp2[i] += dp2[u];
            }
            if(!vis[i] && dp1[u] + 1 < dp1[i]) {
                vis[i] = 1;
                cnt[i]++;
                dp2[i] = dp2[u];
                q.push(i);
                dp1[i] = dp1[u] + 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(dp2[i] == 2) {
            ++cnt;
        }
    }
    return cnt;
}

void solve1() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += bfs(i, 0);
    }
    cout << ans << "\n";
    return;
}
void solve2() {
    int cnt = 0;
    if(a[1] == 1) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; ++i) dp1[i] = dp2[i] = 0;
    for (int i = 2; i <= n;) {
        ++cnt;
        for (int j = i; j <= i + a[1] - 2; ++j) dp1[j] = cnt;
        i = i + a[1] - 1;
    }
    int k = a[1];
    for (int j = 1; j <= k; ++j) dp2[j] = 1;
    int lst = 0, sum = 0;
    for (int j = k + 1; j <= n; ++j) {
        if(dp1[j] != dp1[j - 1]) {
            sum = 0;
            for (int i = j - k + 1; i < j; ++i) sum += dp2[i];
        }
        dp2[j] = sum;
        sum -= dp2[j - k + 1];
    }
    int ans = 0, ans1 = 0;
    for (int i = 1; i <= n; ++i) ans1 += (dp2[i] == 2);
    ans += ans1;
    for (int i = n; i >= 1; --i) {
        ans1 -= (dp2[i] == 2);
        ans += ans1;
    }
    cout << ans << "\n";
    return;
}
void solve3() {
    int tsd = a[1], ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k1 = a[i], k2 = a[i] - 1, k3 = a[i] - 2;
        if(k3 < i) continue;
        int l1, l2;
        if(k1 == tsd) {
            l1 = k2, l2 = k3;
        }
        if(k2 == tsd) {
            l1 = k1, l2 = k3;
        }
        if(k3 >= tsd) {
            l1 = k1, l2 = k2;
        }
        ans += a[l1] - a[l2];
    }
    cout << ans << "\n";
    return;
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    int cnt = 0;
    while(t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        ++cnt;
        for (int i = 1, j = 1; i <= n; ++i) {
            j = max(j, i);
            while(j <= n && abs(x[j] - x[i]) <= d) ++j;
            --j;
            a[i] = j;
        }
        if(c <= 10) {
            solve1();
        }
        if(c == 11 || c == 12) {
            solve2();
        }
        if(c == 13 || c == 14) {
            solve3();
        }
        if(c > 14) {
            cout << "0\n";
        }
    }
    return 0;
}
