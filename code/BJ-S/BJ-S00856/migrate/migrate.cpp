#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 2e6 + 5;
const int inf = 2e9;
typedef long long ll;
int C, T, n, dis[maxn], cnt[maxn], l[maxn], r[maxn];
ll d, a[maxn], ans;
vector <int> e[maxn];
queue <int> q;
void bfs(int x){
    for(int i = x + 1; i <= n; ++i) dis[i] = inf, cnt[i] = 0;
    q.push(x);
    dis[x] = 0, cnt[x] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        if(cnt[u] > 2) continue;
        for(int i : e[u])
            if(dis[i] > dis[u] + 1) dis[i] = dis[u] + 1, cnt[i] = cnt[u], q.push(i);
            else if(dis[i] == dis[u] + 1) cnt[i] = min(3, cnt[i] + cnt[u]);
    }
}
void solve(){
    ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) e[i].clear(), cin >> a[i];
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[j] - a[i] <= d) e[i].push_back(j);
    for(int i = 1; i <= n; ++i){
        bfs(i);
        for(int j = i + 1; j <= n; ++j)
            if(cnt[j] == 2) ans++;
    }
    cout << ans << '\n';
}
void solveA(){
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if(n == 1){
        cout << 0 << '\n';
        return;
    }
    ll gc = a[2] - a[1];
    if(d / gc <= 1) cout << 0 << '\n';
    else cout << max(0ll, n - 2 * (d / gc) + 1) << '\n';
}
void solveB(){
    ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        l[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
        r[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    }
    for(int i = 1; i <= n; ++i) ans += upper_bound(l + 1, l + n + 1, r[i] - 1) - lower_bound(l + 1, l + n + 1, r[i] - 1);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> C >> T;
    if(C >= 11 && C <= 12)
        for(; T; --T) solveA();
    else if(C >= 13 && C <= 14)
        for(; T; --T) solveB();
    else
        for(; T; --T) solve();
    return 0;
}