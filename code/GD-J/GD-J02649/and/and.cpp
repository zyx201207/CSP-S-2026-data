#include <bits/stdc++.h>
using namespace std;
int const N = 2e5;
int n, m, a[N], ans;
int main(){
    freopen("and.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    if (m == 1){
        for (int i = 1; i <= n; i++){
            ans = max(ans, a[i]);
        }
        cout << ans;
    }
    else if (m == 2){
        for (int i = 1; i <= n - 1; i++){
            for (int j = i + 1; j <= n; j++){
                ans = max(ans, (a[i] & a[j]));
            }
        }
    }
    else if (m == 3){
        for (int i = 1; i <= n - 2; i++){
            for (int j = i + 1; j <= n - 1; j++){
                for (int k = j + 1; k <= n; k++){
                    ans = max(ans, (a[i] & a[j] & a[k]));
                }
            }
        }
    }
    else if (m == 4){
        for (int i = 1; i <= n - 3; i++){
            for (int j = i + 1; j <= n - 2; j++){
                for (int k = j + 1; k <= n - 1; k++){
                    for (int x = k + 1; x <= n; x++){
                        ans = max(ans, (a[i] & a[j] & a[k] & a[x]));
                    }
                }
            }
        }
    }
    else if (m == 5){
        for (int i = 1; i <= n - 4; i++){
            for (int j = i + 1; j <= n - 3; j++){
                for (int k = j + 1; k <= n - 2; k++){
                    for (int x = k + 1; x <= n - 1; x++){
                        for (int y = x + 1; y <= n; y++){
                            ans = max(ans, (a[i] & a[j] & a[k] & a[x] & a[y]));
                        }
                    }
                }
            }
        }
    }
    else if (m == 6){
        for (int i = 1; i <= n - 5; i++){
            for (int j = i + 1; j <= n - 4; j++){
                for (int k = j + 1; k <= n - 3; k++){
                    for (int x = k + 1; x <= n - 2; x++){
                        for (int y = x + 1; y <= n - 1; y++){
                            for (int z = y + 1; z <= n; z++){
                                ans = max(ans, (a[i] & a[j] & a[k] & a[x] & a[y] & a[z]));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
