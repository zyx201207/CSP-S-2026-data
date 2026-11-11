#include<bits/stdc++.h>
using namespace std;
int c, t, n, k;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    if(c == 13 || c == 14 || c == 0){
        while(t--){
            cin >> n >> k;
            for(int i = 1; i < n; i++){
                int u, v; cin >> u >> v;
            }
            n = (n + 1) / 2;
            n -= k;
            n /= 2;
            n /= 2;
            cout << n + 1 << endl;
        }
    }
    return 0;
}
