#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 3e18;
const int N = 2e6 + 5, logN = 22;
int n, l[N], r[N];
ll d, a[N], ans;

void subtask1 () {
    ll D = a[2] - a[1];
    int step = d / D;
    if (step <= 1) {
        cout << "0\n";
        return ;
    }
    for (int i = 1; i <= n; ++i)
        if (n - i + 1 >= 2 * step) ans++;
    cout << ans << '\n';
}

void subtask2 () {
    int id = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (l[i] <= 1 && r[i] >= n) cnt++;
    if (cnt >= 3) {
        cout << "0\n";
        return ;
    }
    if (cnt == 1) {
        for (int i = 1; i <= n; ++i)
            if (l[i] <= 1 && r[i] >= n) {
                id = i;
                break ;
            }
        for (int i = 1; i < id; ++i)
            if (r[i] == id + 1) ans += n - r[i];
        for (int i = id + 1; i <= n; ++i)
            if (l[i] == id - 1) ans += l[i] - 1;
        cout << ans << '\n';
    } else {
        for (int i = 1; i <= n; ++i)
            if (l[i] <= 1 && r[i] >= n) {
                id = i;
                break ;
            }
        for (int i = 1; i < id; ++i)
            if (r[i] == id + 1) ans += r[r[i]] - r[i];
        for (int i = id + 1; i <= n; ++i)
            if (l[i] == id) ans += l[i] - l[l[i]];
        cout << ans / 2 << '\n';
    }
}

const int PN = 5e3 + 2;
int dis[PN][PN];
ll cnt[PN][PN];
void brute () {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = 0x3f3f3f3f, cnt[i][j] = 0;
    memset (dis, 0x3f, sizeof(dis));
    memset (cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= r[i]; ++j)
            dis[i][j] = dis[j][i] = cnt[i][j] = cnt[j][i] = 1;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (dis[i][j] == dis[i][k] + dis[k][j])
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                else if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];
                }
            }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (cnt[i][j] == 2) ans++;
    cout << ans << '\n';
}

void solve () {
    cin >> n >> d; ans = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = -INF, a[n + 1] = INF;
    for (int i = 1, pos = 0; i <= n; ++i) {
        while (a[pos] < a[i] - d) ++pos;
        l[i] = pos;
    }
    for (int i = n, pos = n + 1; i >= 1; --i) {
        while (a[pos] > a[i] + d) --pos;
        r[i] = pos;
    }
    bool flag1 = 1, flag2 = 0;
    for (int i = 1; i <= n; ++i)
        flag2 |= (l[i] <= 1 && r[i] >= n);
    for (int i = 2; i < n; ++i)
        flag1 &= (2 * a[i] == a[i - 1] + a[i + 1]);
    if (n <= 500) brute();
    else if (flag1) subtask1();
    else if (flag2) subtask2();
    else brute();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    int Case, T; cin >> Case >> T;
    while (T--) solve();
    return 0;
}
