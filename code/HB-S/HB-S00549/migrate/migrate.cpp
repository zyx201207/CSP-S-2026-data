#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
#define int long long
#define mp make_pair 
int c, T;
const int N = 2e6 + 10;
int nxt[N << 1], to[N << 1], h[N << 1], cnt, ans = 1e9;
void adde(int u, int v) {
    nxt[++cnt] = h[u];
    to[cnt] = v;
    h[u] = cnt;
}
int a[N];
int book[5555];
int g[5005][5005];
inline void bfs(int s) {
    queue<pii> q;
    q.push(mp(s, 0));
    memset(book, 0x3f, sizeof(book));
    while (q.size()){
        pii now = q.front();
        q.pop();
        int u = now.first;
        if (book[u] < now.second) continue;
        g[s][u]++;
        book[u] = now.second;
        for (int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            q.push(mp(v, now.second + 1));
        }
    }
}
void Main() {
    cnt = 0;
    
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n + 1; i ++) {
        nxt[i] = to[i] = h[i] = 0;
        for (int j = 1; j <= n + 1; j++) {
            g[i][j] = 0;
        }
    }
    a[n + 1] = 1e9;
    for (int i = 1; i <= n; i++) {
        int id1 = lower_bound(a + 1, a + n + 1, a[i] + d) - a;
        if (a[id1] > a[i] + d) id1--;
        // cout << i << " " << id1 << endl;
        for (int j = i + 1; j <= id1; j++) {
            adde(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        bfs(i);
    //     for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         // if (g[i][j] == 2) res++;
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl; 
    // }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == 2) res++;
            // cout << g[i][j] << " ";
        }
        // cout << endl;
    }
    cout << res << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--) Main();
    return 0;
}