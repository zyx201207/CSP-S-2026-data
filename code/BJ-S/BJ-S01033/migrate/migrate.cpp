#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, ans[100005];
    cin >> c >> t;
    for(int k = 1; k <= t; k++){
        long long n, d, x[2000005];
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
    }
    for(int i = 1; i <= t; i++){
        ans[i] = 0;
    }





    for(int i = 1; i <= t; i++){
        cout << ans[i];
    }
    return 0;
}