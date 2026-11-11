#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --){
        cin >> n >> d;
        long long c[305][305], e[305][305] = {0}, ans = 0;
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                c[i][j] = 1e9;
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = i + 1;j <= n;j ++){
                if(abs(a[j] - a[i]) <= d){
                    c[i][j] = 1;
                    c[j][i] = 1;
                    e[i][j] = 1;
                    e[j][i] = 1;
                }
            }
        }
        for(int k = 2;k < n;k ++){
            for(int i = 1;i < k;i ++){
                for(int j = k + 1;j <= n;j ++){
                    if(c[i][k] + c[k][j] < c[i][j]){
                        c[i][j] = c[i][k] + c[k][j];
                        e[i][j] = e[i][k] * e[k][j];
                    }else if(c[i][k] + c[k][j] == c[i][j]){
                        e[i][j] += e[i][k] * e[k][j];
                    }
                }
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = i + 1;j <= n;j ++){
                if(e[i][j] == 2){
                    ans ++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
