#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e6 + 5;
const int inf = 1e9 + 9;
int a[maxn], p[maxn];
int n, d;

int dfs(int u, int v, int lim, int dep){
    if(dep > lim || (dep == lim && u != v)) return 0;
    if(u == v && dep == lim) return 1;
    int res = 0;
    for(int i=u+1;i<=min(n, p[u]);i++){
        if(a[i] - a[u] > d) break;
        res += dfs(i, v, lim, dep + 1);
    }
    return res;
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C, T;
    cin >> C >> T;
    while(T--){
        cin >> n >> d;
        int ans = 0;
        for(int i=1;i<=n;i++) cin >> a[i];
        a[n+1] = inf;
        for(int i=1;i<=n;i++){
            int x = upper_bound(a+1, a+n+2, a[i]+d) - a - 1;
            if((a[x] - a[i]) > d) p[i] = i;
            else p[i] = x;
        }

        //for(int i=1;i<=n;i++) cout << p[i] << ' ';

        for(int i=1;i<n;i++){
            if(p[i] == i) continue;
            for(int j=p[i]+1;j<=n;j++){
                int x = p[i], lim = 2;
                while(p[x] < j){
                    x = p[x];
                    lim ++;
                }
                ans += (dfs(i, j, lim, 0) == 2);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
