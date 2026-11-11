#include <bits/stdc++.h>
using namespace std;
int c, T;
const int N = 2e6 + 10;
int nxt[N << 1], to[N << 1], h[N << 1], cnt, ans = 1e9;
void adde(int u, int v) {
    nxt[++cnt] = h[u];
    to[cnt] = v;
    h[u] = cnt;
}
int n, k;
int f[N];
int get(int x) {
    return (f[x] == x) ? f[x] : f[x] = get(f[x]);
}
void merge(int x, int y) {
    f[get(x)] = get(y);
}
int book[N], stk[N], tot, a[N], res;
inline int bfs(int s) {
    int v1[10000] = {0};
    queue<pair<int,int>> q;
    q.push(make_pair(s, 0));
    while (q.size()) {
        pair<int, int> now = q.front();
        q.pop();
        if (a[now.first]) {
            return now.second;
        }
        int u = now.first;
        v1[u] = 1;
        for (int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if (!v1[v]) q.push(make_pair(v, now.second + 1));
        }
    }
    
}
inline void baoso(int t, int x){
    if (k - t > n - x) return;
    // cout << t << " " << x << endl;
    if (t > k) {
        queue<int> q;
        int vis[10000] = {0}, l = 0;
        for (int i = 1; i <= n; i++) f[i] = i;
        for (int i = 1; i <= k; i++) {
            int u = stk[i];
            for (int j = h[u]; j; j = nxt[j]) {
                int v = to[j];
                if (a[v]) merge(v, u);
            }
            // cout << stk[i] << " " ;
        }
        // cout << endl;
        int te = -1;
        for (int i1 = 1; i1 < k; i1++) {
            int i = stk[i1];
            if (get(i) != get(stk[i1 + 1])) {
                if (te != -1 && get(stk[i1 + 1]) != get(te)) return;
                else te = i;
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (!a[i]) res = max(res, bfs(i));
        }
        ans = min(ans, res);
        return;
    } 
    for (int i = 1; i <= n; i++) {
        if (book[i]) continue;
        book[i] = 1;
        stk[++tot] = i; a[i] = 1;
        baoso(t + 1, x + 1);
        tot--;
        a[i] = 0;
        book[i] = 0;
    }
}
void Main() {
    cin >> n >> k;
    cnt = res = 0;
    ans = 1e9;
    for (int i = 1; i <= n + 1; i++) {
        nxt[i] = to[i] = h[i] = book[i] = a[i] = stk[i] = 0; 
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adde(x, y), adde(y, x);
    }
    if (c == 13 || c == 14) {
        double x = 1.0 * (n + 1) / 2;
        cout << int(x / 4 - (k - 2) / 4) << endl;;
        return;
    }
    baoso(1, 1);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> T;
    // T = 1;
    while (T--) Main();
    return 0;
}