#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int c, T;
int n, d, a[N], l[N], r[N];
int dis[N], cnt[N];
void bfs(int s){
    for (int i = 1;i <= n;i++)
        dis[i] = -1, cnt[i] = 0;
    queue<int> q;
    q.push(s);
    dis[s] = 0, cnt[s] = 1;
    int t;
    while (!q.empty()){
        t = q.front(); q.pop();
        for (int i = l[t];i <= r[t];i++){
            if (i == t) continue;
            if (dis[i] == -1){
                dis[i] = dis[t] + 1;
                cnt[i] = cnt[t];
                q.push(i);
            }
            else if (dis[i] == dis[t] + 1){
                cnt[i] += cnt[t];
            }
        }
    }
}
void solve(){
    cin >> n >> d;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++){
        l[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
        r[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    }
    if (c == 11 || c == 12){
        int maxl = d / (a[2] - a[1]);
        cout << max(0ll, n - (2 * maxl + 1)) << endl;
        return;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++){
        bfs(i);
        for (int j = 1;j < i;j++)
            if (cnt[j] == 2) ans++;
    }
    cout << ans << endl;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--) solve();
}
