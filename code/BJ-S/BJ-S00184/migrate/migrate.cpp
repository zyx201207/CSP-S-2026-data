#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2000005;
ll c, t, n, d, a[N], l[N], r[N], L[N], R[N];
vector<int> g[N];
int dis[5005][5005], cnt[5005][5005]; bool vis[5005];
priority_queue<pair<int, int> > q;
vector<int> four;
ll stk[N], tp = 0;
int checkl(int x) {
    int nl = 1, nr = tp, res = 0;
    while (nl <= nr) {
        int mid = (nl + nr) >> 1;
        if (a[x - 1] - a[stk[mid]] <= d) {
            nr = mid - 1;
        } else {
            res = mid;
            nl = mid + 1;
        }
    }
    return res;
}
void modifyl(int x, int y) {
    tp = checkl(y);
    for (int i = l[y]; i < y; i++) stk[++tp] = i;
}
int checkr(int x) {
    int nl = 1, nr = tp, res = 0;
    while (nl <= nr) {
        int mid = (nl + nr) >> 1;
        if (a[stk[mid]] - a[x + 1] <= d) {
            nl = mid + 1;
        } else {
            res = mid;
            nr = mid - 1;
        }
    }
    return res;
}
void modifyr(int x, int y) {
    tp = checkr(y);
    for (int i = r[y]; i > y; i--) stk[++tp] = i;
}
void abnormal() {
    for (int i = 1; i <= n; i++) l[i] = r[i] = L[i] = R[i] = 0; tp = 0;
    four.clear();
    for (int i = 1; i <= n - 3; i++) {
        if (a[i + 2] - a[i] <= d && a[i + 3] - a[i] > d && a[i + 3] - a[i + 1] <= d) {
            four.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(a + 1, a + i, a[i] - d) - a;
        r[i] = upper_bound(a + i + 1, a + n + 1, a[i] + d) - a - 1;
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (tmp != l[i]) modifyl(tmp, l[i]), tmp = l[i];
        if (l[i] != i) L[i] = checkl(i);
        // L[i] += (i - l[i] + 1);
    }
    tmp = n + 1; tp = 0;
    for (int i = n; i >= 1; i--) {
        if (tmp != r[i]) modifyr(tmp, r[i]), tmp = r[i];
        if (r[i] != i) R[i] = checkr(i);
        // R[i] += (r[i] - i + 1);
    }
    // for (int i = 1; i <= n; i++) cout << l[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) cout << L[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) cout << r[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) cout << R[i] << " \n"[i == n];
    ll ans = 0;
    for (int i = 0; i < four.size(); i++) {
        int x = four[i], y = x + 3;
        ll nl = L[x] + 1, nr = R[y] + 1;
        nl += (lower_bound(a + 1, a + x, a[x + 1] - d) - a) - l[x];
        nr += r[y] - (upper_bound(a + y + 1, a + n + 1, a[y - 1] + d) - a) + 1;
        ans += nl * nr;
    }
    cout << ans << '\n';
}
void dijkstra(int x) {
    for (int i = 1; i <= n; i++) dis[x][i] = 0x3f3f3f3f, cnt[x][i] = 0, vis[i] = 0; dis[x][x] = 0, cnt[x][x] = 1;
    q.push(make_pair(0, x));
    while (!q.empty()) {
        int u = q.top().second, d = q.top().first;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (dis[x][v] > dis[x][u] + 1) {
                cnt[x][v] = cnt[x][u];
                dis[x][v] = dis[x][u] + 1;
                q.push(make_pair(-dis[x][v], v));
            } else if (dis[x][v] == dis[x][u] + 1) cnt[x][v] += cnt[x][u];
        }
    }
}
void normal() {
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] - a[j] <= d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) dijkstra(i);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            // cout << i << ' ' << j << ':' << dis[i][j] << ' ' << cnt[i][j] << '\n';
            if (cnt[j][i] == 2) ans++;
        }
    }
    cout << ans << '\n';
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (c <= 10) normal();
        else abnormal();
    }
    return 0;
}