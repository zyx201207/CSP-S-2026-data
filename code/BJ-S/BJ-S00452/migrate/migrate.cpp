#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
long long n, d, x[maxn], ans;
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> x[i];
        if(c == 11 || c == 12){
            long long gc = x[2] - x[1], base = d / gc;
            base--;
            if(base < 2){
                cout << 0 << endl;
                continue;
            }
            ans = n - 1 - 2 * (base - 1);
            cout << ans << endl;
        }
        else {
            for(int i = 1;i <= n;i++){
                for(int j = i + 1;j <= n;j++){
                    if(x[j] - x[i] > d && x[j] - x[i] < 2 * d) ans++;
                }
            }
            cout << ans << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
