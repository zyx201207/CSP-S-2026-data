#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
#define int long long 
#define pii pair<int, int>
#define mk make_pair
const int N = 2e6 + 5, inf = 1e9;
int n, d, a[N], dis[N]; 
int ans, f[N];
bool vis[N], flg[N];
int s[N];
priority_queue<pii, vector<pii>, greater<pii> >q;
inline void dij(int s){
    for(int i=1;i<=n;i++) f[i] = 0, dis[i] = inf, vis[i] = 0;
    q.emplace(mk(0, s)); dis[s] = 0; f[s] = 1;
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = 1; ans += f[u] == 2 ? 1 : 0;
        for(int v=u+1;v<=n && a[v] - a[u] <= d;v++){
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1; f[v] = f[u];
                if(!vis[v]) q.emplace(mk(dis[v], v));
            }else if(dis[v] == dis[u] + 1) f[v] += f[u];
        }
    }
}
inline void solve(){
    cin >> n >> d; ans = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n == 1) return cout << 0 << '\n', void();
    for(int i=1;i<=n;i++) dij(i);
    cout << ans << '\n';
}
inline void solveA(){
    cin >> n >> d; ans = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n == 1) return cout << 0 << '\n', void();
    int dd = a[2] - a[1]; int pos = d / dd;
    for(int i=2;i<=n;i++){
        int L = max(1ll, i - pos);
        int R = L + 1;
        if(R >= i) continue;
        int LL = max(0ll, L - pos), RR = max(0ll, R - pos);
        if(LL <= RR && RR) ans ++; 
    }
    cout << ans << '\n';
}
inline void solveB(){
    cin >> n >> d; ans = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    int id = 0;
    if(n == 1) return cout << 0 << '\n', void();
    for(int i=1;i<=n;i++) 
        if(a[i] + d >= a[n] && a[i] - d <= a[1]) flg[i] = 1, id = i;
        else flg[i] = 0;
    for(int i=1;i<=n;i++) s[i] = s[i - 1] + (flg[i] ? 1 : 0);
    for(int i=2;i<=n;i++){
        if(flg[i]) continue;
        int R = lower_bound(a + 1, a + n + 1, a[i] - d) - a - 1;
        int L = lower_bound(a + 1, a + n + 1, a[R + 1] - d) - a;
        int val = max(0ll, R - L + 1);
        val -= (s[R] - s[L - 1]);
        if(a[id] == a[L] + d && a[id] + d == a[i]) --val;
        val = max(val, 0ll);
        ans += val;
    }   
    cout << ans << '\n';
}
signed main(){
    FILE("migrate");
    cin.tie(nullptr) -> sync_with_stdio(false);
    int cid, T; cin >> cid >> T;
    while(T--){
        if(cid == 11 || cid == 12) solveA();
        else if(cid == 13 || cid == 14) solveB();
        else solve();
    } 
    return 0;
}