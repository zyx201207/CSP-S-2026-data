#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
bool flag[200005];
signed main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(flag , 1 , sizeof(flag));
    int ans = 0;
    for (int i = 30; i >= 0; i--){
        int cnt = 0;
        for (int j = 1; j <= n; j++){
            if (flag[j] && (a[j] & (1ll << i))) cnt++;
        }
        if (cnt < m) continue;
        for (int j = 1; j <= n; j++){
            if ((a[j] & (1ll << i)) == 0) flag[j] = false;
        }
        ans += (1ll << i);
    }
    cout << ans;
    return 0;
}
