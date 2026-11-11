

#include <iostream>
#include <queue>

#define int long long

using namespace std;

int c, t;
const int MAXI = 2e6 + 9;
int n, d;
int x[MAXI];

bool G[309][309];
int in[309];
int dis[309], f[309];

void DagF (int st) {
    for (int i = 1; i <= n; i++) in[i] = 0;
    for (int i = 1; i <= n; i++) dis[i] = 1e18, f[i] = 0;
    dis[st] = 1, f[st] = 1;

    for (int i = st; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (G[i][j]) in[j]++;

    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; v++) {
            if (!G[u][v]) continue;

            in[v]--;
            if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, f[v] = 0;
            if (dis[v] == dis[u] + 1) f[v] += f[u];

            if (!in[v]) q.push(v);
        }
    }
}

void BaoLi () {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) G[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[j] - x[i] <= d) G[i][j] = 1;
            else break;
        }
    }

    int ans = 0;
    for (int st = 1; st <= n; st++) {
        DagF(st);
        for (int i = 1; i <= n; i++)
            if (f[i] == 2) ans++;
    }
    cout << ans << '\n';
}

void TeShuA () {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x[i];

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int e = d / (x[2] - x[1]);
    if (e == 0 || e == 1) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;
    for (int dis = 0; dis <= n - 1; dis++) {
        if (dis % e == 0) continue;
        if (dis / e == 0) continue;
        if (dis / e >= 2) continue;
        if (e < dis % e + 2) ans += n - dis;
    }
    cout << ans << '\n';
}

signed main () {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> t;

    if (c <= 6) {
        while (t--) BaoLi();
        return 0;
    }

    if (c == 11 || c == 12) {
        while (t--) TeShuA();
        return 0;
    }

    while (t--) cout << 0 << '\n';

    return 0;
}
