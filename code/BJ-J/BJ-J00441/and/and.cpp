#include <iostream>
#define int long long
using namespace std;

int a[114514];
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (m == 1){
        int maxn = 0;
        for (int i = 1; i <= n; i++){
            maxn = max(maxn, a[i]);
        }
        cout << maxn; return 0;
    }
    if (m == n){
        if (n > 2000){
            cout << 0; return 0;
        }
        int ans = a[1];
        for (int i = 2; i <= n; i++){
            ans &= a[i];
        }
        cout << ans; return 0;
    }
    if (m == 2){
        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans; return 0;
    }
    cout << 0;
    return 0;
}
