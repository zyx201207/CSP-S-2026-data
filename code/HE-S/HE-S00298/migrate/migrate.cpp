#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 10;
#define int long long
typedef pair <int ,int> pii;
int c, t;
int n, d, x[N], cnt = 0, mi;

void dfs(int i, int j, int dep) {
    //cout << i << endl;
    if(dep > mi) return ;
    if(i == j) {cnt ++; return ;}
    for(int k = i + 1;k <= j;k ++) {
        if(x[k] - x[i] <= d) dfs(k, j, dep + 1);
    }
}

void solve(){
    int ans = 0;
    cin >> n >> d;
    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int i = 1;i <= n;i ++) {
        for(int j = i + 1;j <= n;j ++){
            cnt = 0, mi = INT_MAX;
            int k = i, sum = 0; bool f = 0;
            while(k < j) {
                int id = k;
                for(; x[id] - x[k] <= d && id <= j; id++);
                if(id - 1 == k) {f = 1; break;}
                k = id - 1, sum ++;
            }
            if(f) continue;
            mi = sum;
            //if(i == 1 && j == 4) cout << mi << endl;
            dfs(i, j, 0);
            if(cnt == 2) ans++;
        }
    }
    cout << ans << endl;
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) solve();
    return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
