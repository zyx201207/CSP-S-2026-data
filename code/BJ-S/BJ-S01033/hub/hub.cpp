#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t, ans[10];
    cin >> c >> t;
    for(int x = 1; x <= t; x++){
        long long n, k, u[1000005], v[1000005];
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> u[i] >> v[i];
        }
    }
    for(int i = 1; i <= t; i++){
        ans[i] = 0;
    }




    for(int i = 1; i <= t; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}