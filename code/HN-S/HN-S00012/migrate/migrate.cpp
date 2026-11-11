#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e6 + 5;
const int N = 5005;
int c, t, n;
ll d, x[MAXN];
vector<int> G[MAXN];

bool vis[N];
int cnt[N], dis[N];

int bfs(int u) {
    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
        cnt[i] = 0;
        dis[i] = 0;
    }
    cnt[u] = 1;
    vis[u] = true;

    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int to : G[now]) {
            if (!vis[to] || dis[to] == dis[now] + 1) {
                if (!vis[to]) {
                    dis[to] = dis[now] + 1;
                    q.push(to);
                    vis[to] = true;
                }
                // cnt[to] = min(3, cnt[to] + cnt[now]);
                cnt[to] += cnt[now];
            }
        }
    }

    int ans = 0;
    for (int i = u + 1; i <= n; ++i) {
        ans += (cnt[i] == 2);
    }
    return ans;
}

void clear() {
    for (int i = 1; i <= n; ++i) G[i].clear();
}

// ---------- A -----------

bool checkA() {
    for (int i = 3; i <= n; ++i) {
        if (x[i] - x[i - 1] != x[i - 1] - x[i - 2]) return false;
    }
    return true;
}

void solveA() {
    if (x[n] - x[1] <= d) {
        cout << 0 << '\n';
    } else {
        int pos = 0;
        while (pos < n && x[pos + 1] - x[1] <= d) ++pos;
        if (pos <= 2) {
            cout << 0 << '\n';
        } else {
            int x = pos - 1 + pos - 1;
            cout << max(0, n - x + 1) << '\n';
        }
    }
}

// ---------- A -----------

// ---------- B -----------

bool checkB() {
    return c >= 13 && c <= 14;
}

void solveB() {
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int R1 = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        if (R1 >= i + 2) {
            int L = upper_bound(x + 1, x + n + 1, x[R1 - 2] + d) - x;
            int R = upper_bound(x + 1, x + n + 1, x[R1 - 1] + d) - x;
            ans += R - L;
        }
    }
    cout << ans << '\n';
}

// ---------- B -----------

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    if (checkA()) {
        solveA();
        return;
    } else if (checkB()) {
        solveB();
        return;
    }

    for (int i = 1; i <= n; ++i) {
        int cL = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
        int cR = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        for (int j = cL; j <= cR; ++j) if (i != j) G[i].push_back(j);
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) res += bfs(i);
    cout << res << '\n';

    clear();
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> t;
    while (t--) solve();
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/