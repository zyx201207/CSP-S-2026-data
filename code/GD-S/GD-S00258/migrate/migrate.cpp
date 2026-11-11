#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
const int N = 2000005;
ll Testid, T, n, d, ans;
ll a[N], dis[N], cnt[N], pos[N];
vector <int> G[N];
void bfs(int s) {
    for (int i = s; i <= n; i++) dis[i] = IMX, cnt[i] = 0;
    queue <int> q; q.push(s), dis[s] = 0, cnt[s] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto v : G[cur]) {
            if (dis[cur] + 1 < dis[v]) dis[v] = dis[cur] + 1, q.push(v), cnt[v] = cnt[cur];
            else if (dis[cur] + 1 == dis[v]) cnt[v] += cnt[cur], cnt[v] = min(cnt[v], 3ll);
        }
    }
    for (int i = s; i <= n; i++) { if (cnt[i] == 2) ans++; }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> Testid >> T;
    while (T--) {
        cin >> n >> d; ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], G[i].clear();
        for (int i = 1; i <= n; i++) pos[i] = upper_bound(a + i, a + 1 + n, a[i] + d) - a - 1;
        if (n <= 5000) {
            for (int i = 1; i <= n; i++) { for (int j = pos[i]; j > i; j--) G[i].push_back(j); }
            for (int i = 1; i <= n; i++) bfs(i);
        }
        else if (Testid >= 11 and Testid <= 12) {
            if (n == 1) ans = 0;
            else {
                ll t = pos[1] - 1;
                if (t == 0 or t == 1) ans = 0;
                else { for (int i = n; i >= 1; i--) { if (i + 2 * t - 1 <= n) ans++; } }
            }
        }
        else if (Testid >= 13 and Testid <= 14) {
            int p = n;
            for (int i = 1; i <= n; i++) { if (pos[i] == n) { p = i; break; } }
            if (p + 1 <= n) { for (int i = p - 2; i >= 1; i--) { if (pos[i] < p + 1 and pos[p - 1] >= p + 1 and pos[p - 2] < p + 1) ans++; } }
            if (p + 2 <= n) {
                for (int i = p - 1; i >= max(1, p - 2); i--) {
                    if (i == p - 1) { if (pos[i] == p + 1) ans++; }
                    else { if (pos[i + 1] >= p + 2 and pos[i] < p + 1) ans++; }
                }
            } 
            for (int i = p - 1; i >= 1; i--) {
                int t = max(p + 3ll, pos[i] + 1), cnt = 0;
                if (t > n or pos[i] >= p + 2) continue;
                if (pos[i] == p + 1) {
                    if (i != p - 1) t = max(pos[p - 1] + 1, (ll)(t));
                    ans += n - t + 1;
                }
                else {
                    if (i == p - 1) continue;
                    if (i == p - 2) { if (pos[p - 1] + 1 <= t) ans += t - pos[p - 1]; }
                    else ans += pos[p - 1] - pos[p - 2];
                }
            }
        }
        else ans = 0;
        cout << ans << '\n';
    }
    return 0;
}