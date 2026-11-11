#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e6 + 10, inf = 0x3f3f3f3f;

int C, T, n;
ll d, x[MAXN]; 

namespace sub1{
    const int N = 3e2 + 10;
    int f[N][N], minc[N][N];
    void work(){
        cin >> n >> d;
        for(int i = 1; i <= n; i ++){
            cin >> x[i];
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                f[i][j] = 0;
                minc[i][j] = inf;
                if(i == j){
                    f[i][j] = 1;
                    minc[i][j] = 0;
                }
            }
        }
        /*
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                for(int k = j - 1; k >= i; k --){
                    if(x[j] - x[k] > d) break;
                    minc[i][j] = min(minc[i][j], minc[i][k] + 1);
                }
            }
        }
        */
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                for(int k = j - 1; k >= i; k --){
                    if(x[j] - x[k] > d) break;
                    if(minc[i][k] + 1 < minc[i][j]){
                        minc[i][j] = minc[i][k] + 1;
                        f[i][j] = min({3, f[i][k]});
                    }else if(minc[i][k] + 1 == minc[i][j]){
                        f[i][j] = min({3, f[i][j] + f[i][k]});
                    }
                }
            }
        }
        // for(int i = 1; i <= n; i ++){
        //     for(int j = i + 1; j <= n; j ++){
        //         cerr << minc[i][j] << " ";
        //     }
        //     cerr << "\n";
        // }

        // for(int j = 1; j <= n; j ++){
        //     for(int i = j - 1; i >= 1; i --){
        //         if(x[j] - x[i] > d) break;
        //         if(i == j - 1){
        //             f[i][j] = 1, minc[i][j] = 1;
        //         }else{
        //             for(int k = i; k < j; k ++){
        //                 if(minc[i][j] == minc[i][k] + minc[k][j]){
        //                     f[i][j] = min({3, f[i][j] + f[i][k] * f[k][j] } );
        //                 }else if(minc[i][j] > minc[i][k] + minc[k][j]){
        //                     minc[i][j] = minc[i][k] + minc[k][j];
        //                     f[i][j] = min({3, f[i][k] * f[k][j] });
        //                 }
        //             }
        //         }
        //     }
        // }

        int ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                // cerr << f[i][j] << " " << minc[i][j] << " || ";
                if(f[i][j] == 2)ans++;
            }
            // cerr << "\n";
        }
        cout << ans << "\n";
    }
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    
    cin >> C >> T;
    while(T--){
        sub1::work();
    }

    return 0;
}