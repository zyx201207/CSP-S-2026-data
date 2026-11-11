#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5 , inf = 0x3f3f3f3f3f3f;
namespace one{
    int n , m , a[N] , l[N] , r[N] , dis[N] , b[N] , f[N] , ans;
    void solve(int cases){
        while (cases--){
            cin >> n >> m;
            for (int i = 0;i <= n + 1;i++) f[i] = 0;
            for (int i = 1;i <= n;i++) cin >> a[i];
            for (int i = 1 , j = 1;i <= n;i++){
                while (a[i] - a[j] > m) ++j;
                l[i] = j;
            }
            for (int i = 1 , j = 1;i <= n;i++){
                while (j < n && a[j + 1] - a[i] <= m) ++j;
                r[i] = j;
            }
            for (int i = 1;i <= n;i++){
                for (int j = 0;j <= n + 1;j++) dis[j] = inf;
                for (int j = 1;j <= i;j++) dis[j] = 0;
                for (int j = i + 1;j <= n;j++) dis[j] = dis[l[j]] + 1;
                for (int j = n;j >= 1;j--){
                    if (dis[j] == dis[j + 1]) b[j] = b[j + 1];
                    else b[j] = j;
                }
                for (int j = i;j <= n;j++){
                    if (l[j] == j && j != i) break;
                    if (dis[j] <= 1){
                        f[j] = 1;
                        continue;
                    }
                    int d = b[l[j]] - l[j];
                    if (!d) f[j] = f[l[j]];
                    else if (d == 1) f[j] = f[l[j]] + f[l[j] + 1];
                    else f[j] = 3;
                    if (f[j] >= 3) f[j] = 3;
                    ans += (f[j] == 2);
                }
            }
            cout << ans << '\n';
            ans = 0;
        }
    }
}
namespace two{
    int n , m , a[N] , l[N] , r[N] , b[N] , k , f[N] , ans;
    int check(int x){
        return (*lower_bound(b + 1 , b + k + 1 , x)) - x;
    }
    void solve(int cases){
        while (cases--){
            cin >> n >> m;
            for (int i = 1;i <= n;i++) cin >> a[i];
            for (int i = 1 , j = 1;i <= n;i++){
                while (a[i] - a[j] > m) ++j;
                l[i] = j;
            }
            for (int i = 1 , j = 1;i <= n;i++){
                while (j < n && a[j + 1] - a[i] <= m) ++j;
                r[i] = j;
            }
            b[0] = -1;
            for (int i = 1;i <= n;i++){
                k = 0;
                b[++k] = i;
                while (r[b[k]] != b[k]) b[k + 1] = r[b[k]] , ++k;
                // for (int tmp = 1;tmp <= k;tmp++) cout << b[tmp] << ' ';
                // cout << '\n';
                for (int tmp = 1;tmp <= k;tmp++){
                    for (int j = b[tmp] - 1;j <= b[tmp];j++){ 
                        if (l[j] <= i){
                            f[j] = 1;
                            continue;
                        }
                        int d = check(l[j]);
                        if (!d) f[j] = f[l[j]];
                        else if (d == 1) f[j] = f[l[j]] + f[l[j] + 1];
                        else f[j] = 3;
                        if (f[j] >= 3) f[j] = 3;
                    }
                }
                // for (int j = i;j <= n;j++) ans += (f[j] == 2);
                // for (int j = i;j <= n;j++) cout << f[j] << ' ';
                // cout << '\n';
                for (int tmp = 1;tmp < k;tmp++){
                    int j = b[tmp];
                    if (f[j] == 3) continue;
                    else if(f[j] == 2){
                        // r[j - 1] + 1 ~ r[j]
                        if (b[tmp - 1] == j - 1) ans += b[tmp + 1] - b[tmp];
                        else ans += r[j] - r[j - 1];
                    }
                    else{
                        if (b[tmp - 1] == j - 1 || j == i || f[j - 1] >= 2) continue;
                        else ans += r[j - 1] - r[j - 2];
                    }
                }
                // cout << ans << '\n';
                // ans = 0;
            }
            cout << ans << '\n';
            // cout << '\n';
            ans = 0;
        }
    }
}
signed main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int caseid , cases;
    cin >> caseid >> cases;
    if (caseid <= 10 && caseid) one::solve(cases);
    else two::solve(cases);
}