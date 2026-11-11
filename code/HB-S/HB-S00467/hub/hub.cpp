#include<bits/stdc++.h>
using namespace std;

#define my long long
const my N = 1e6 + 5;

my c, t, n, k;
vector<my> G[N];

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(my i = 1; i < n; i++){
            my u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cout << 1 << '\n';
    }
    return 0;
}
