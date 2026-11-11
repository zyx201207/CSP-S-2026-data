#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        int ans = n ^ k;
        for (int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            ans ^= u, ans ^= v;
        }
        cout << ans << '\n';
    }
    return 0;
}
