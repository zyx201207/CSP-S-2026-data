#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
long long a[N], ans;
bool vis[N];
void dfs(int x, int cnt, long long res){
    if (cnt == m){
        ans = max(ans, res);
        return ;
    }
    if (cnt == 0){
        dfs(x + 1, cnt + 1, a[x]);
        dfs(x + 1, cnt, res);
    }
    else {
        dfs(x + 1, cnt + 1, res & a[x]);
        dfs(x + 1, cnt, res);
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;++ i) cin >> a[i];
    if (m == 3){
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= n;++ j)
                for (int k = 1;k <= n;++ k)
                    if (i != j && j != k && i != k)
                        ans = max (ans, a[i] & a[j] & a[k]);
        cout << ans ;
        return 0;
    }
    if (m == 4){
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= n;++ j)
                for (int k = 1;k <= n;++ k)
                    for (int f = 1;f <= n;++ f)
                        if (i != j && i != f && j != k && i != k && k != f && j != f)
                            ans = max (ans, a[i] & a[j] & a[k]);
        cout << ans;
        return 0;
    }
    if (m == 5) {
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= n;++ j)
                for (int k = 1;k <= n;++ k)
                    for (int f = 1;f <= n;++ f)
                        for (int h = 1;h <= n;++ h)
                            if (i != j&&i!=k&&i!=f&&i!=h&&j!=k&&j!=f&&j!=h&&k!=f&&k!=h&&f!=h)
                                ans = max (ans, a[i] & a[j] & a[k] &a[h]);
        cout <<ans ;
        return 0;
    }
    if (m == 1){
        for (int i = 1;i <= n;++ i){
            ans = max(ans, a[i]);
        }
        cout << ans ;
        return 0;
    }
    if (m == n){
        ans = a[1];
        for (int i = 2;i <= n;++ i)
            ans &= a[i];
        cout << ans;
        return 0;
    }
    if (m == 2){
        for (int i = 1;i <= n;++ i){
            for (int j = 1;j <= n;++ j){
                if (i == j) continue;
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if (m == n - 1){
        long long sum = a[1];
        for (int i = 2;i <= n;++ i)
            sum &= a[i];
        for (int i = 1;i <= n;++ i)
            ans = max (ans, sum & a[i]);
        cout << ans;
        return 0;
    }
    if (n <= 20){
        dfs(1, 0, 0);
        cout << ans ;
        return 0;
    }
    return 0;
}
