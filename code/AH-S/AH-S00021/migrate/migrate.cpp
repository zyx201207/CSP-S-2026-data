#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, x[N];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
        while(t--){
            cin >> n >> d;
            for(int i = 1; i <= n; i++) cin >> x[i];
            int p = x[2] - x[1];
            if(p >= d) cout << 0 << '\n';
            else cout << n - (d / p) + 1 << '\n';
        }
    return 0;
}
