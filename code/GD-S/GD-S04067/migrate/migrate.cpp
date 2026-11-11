#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;

const int maxn = 2e6 + 5;
int f[maxn][2][2], n, head[maxn], cur, nxt[maxn];
ll a[maxn], d, ans;
struct edge{int v, nxt;}E[maxn]; void add(int u, int v){E[++cur] = {v, head[u]}; head[u] = cur;}
bool vis[maxn];

void init(){
    for(int i = 1; i <= n; i++) head[i] = 0;
    cur = 0;
}

void dfs(int u, int fa){
    vis[u] = 1;
    memset(f[u], 0, sizeof(f[u]));
    for(int i = head[u]; i; i = E[i].nxt){
        int v = E[i].v;
        dfs(v, u);
        if(a[u] - a[v - 2] > d){
            int op = (a[u - 1] - a[v - 1]) <= d;
            if(a[u] - a[v - 1] <= d){
                f[u][1][op] += f[v][0][0];
            }else{
                f[u][0][op] += f[v][0][0] + f[v][0][1];
                f[u][1][op] += f[v][1][0] + f[v][1][1];
            }
        }
        f[u][0][0]++;
    }
    if(!fa || (u == 1)) return ;
    int l = u + 1, r = fa;
    l = max(l, nxt[u - 2] + 1);
    int L = l, R = min(r, nxt[u - 1]);
    ans += 1ll * max(0, R - L + 1) * f[u][0][0];
    L = max(l, nxt[u - 1] + 1); R = r;
    ans += 1ll * max(0, R - L + 1) * (f[u][1][0] + f[u][1][1]);
    // for(int x = l; x <= fa; x++){
    //     // if(a[x] - a[u - 2] <= d) continue;
    //     if(a[x] - a[u - 1] <= d){
    //         ans += f[u][0][0];
    //     }else{
    //         ans += f[u][1][0] + f[u][1][1];
    //     }
    // }
}

void solve(){
    init();
    cin >> n >> d;
    a[0] = -4e18;
    for(int i = 1; i <= n; i++) cin >> a[i];
    nxt[0] = 0;
    for(int i = 1, j = 1; i <= n; i++){
        while(j + 1 <= n && a[j + 1] - a[i] <= d) j++;
        if(i != j) add(j, i);
        vis[i] = 0;
        nxt[i] = j;
    }
    ans = 0;
    for(int i = n; i >= 1; i--) if(!vis[i]){
        dfs(i, 0);
    }
    cout << ans << '\n';
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, t; cin >> c >> t; while(t--) solve();

    return 0;
}
