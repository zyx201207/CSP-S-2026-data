#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1000005;
const int inf = 1e18;
int f[maxn], sum;
struct S{
    int x, y;
}a[maxn];
int fi(int x){
    if(f[x] == x) return x;
    return f[x] = fi(f[x]);
}
void join(int x, int y){
    f[fi(x)] = fi(y);
}
vector<int> v[maxn];
bool vis[maxn];
void dfs(int x, int fr, int d){
    if(vis[x]){
        sum = min(sum, d);
        return ;
    }
    for(int i : v[x]){
        if(i == fr) continue;
        dfs(i, x, d + 1);
    }
}
void dfs1(int x, int fr, int d){
    f[x] = min(f[x], d);
    for(int i : v[x]){
        if(i == fr) continue;
        dfs1(i, x, d + 1);
    }
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, k, ans = inf;
        cin >> n >> k;
        if(n <= 10){
            for(int i = 1;i < n;i++){
                cin >> a[i].x >> a[i].y;
                v[a[i].x].push_back(a[i].y);
                v[a[i].y].push_back(a[i].x);
            }
            for(int i = 1;i < (1 << n);i++){
                if(__builtin_popcount(i) != k) continue;
                for(int j = 1;j <= n;j++) f[j] = j;
                for(int j = 1;j < n;j++){
                    if(((i >> (a[j].x - 1)) & 1) && ((i >> (a[j].y - 1)) & 1)) join(a[j].x, a[j].y);
                }
                int cnt = 0;
                for(int j = 1;j <= n;j++){
                    if((i >> (j - 1)) & 1){
                        if(f[j] == j) cnt++;
                    }
                }
                if(cnt <= 2){
                    for(int j = 1;j <= n;j++) vis[j] = ((i >> (j - 1)) & 1);
                    int now = 0;
                    for(int j = 1;j <= n;j++){
                        if((i >> (j - 1)) & 1) continue;
                        sum = inf;
                        dfs(j, 0, 0);
                        now = max(now, sum);
                    }
                    ans = min(ans, now);
                }
            }
            for(int i = 1;i <= n;i++) v[i].clear();
            cout << ans << "\n";
        }else if(k == 2){
            for(int i = 1;i < n;i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
            }
            for(int i = 1;i <= n;i++){
                for(int j = i + 1;j <= n;j++){
                    for(int k = 1;k <= n;k++) f[k] = inf;
                    dfs1(i, 0, 0);
                    dfs1(j, 0, 0);
                    int now = 0;
                    for(int k = 1;k <= n;k++) now = max(now, f[k]);
                    ans = min(ans, now);
                }
            }
            for(int i = 1;i <= n;i++) v[i].clear();
            cout << ans << "\n";
        }
    }
    return 0;
}