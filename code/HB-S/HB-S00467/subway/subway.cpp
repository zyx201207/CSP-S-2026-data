#include<bits/stdc++.h>
using namespace std;

#define my long long
const my N = 5e5 + 5;

my c, n, m, d, q, w[N], k[505];

struct edge{
    my v, w;
};

vector<edge> G[N];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(my i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(my i = 1; i <= n; i++){
        cin >> k[i];
        for(my j = 1; j <= k[i]; j++){
            my a, t;
            cin >> a >> t;
            G[i].push_back(edge{a, t});
            G[a].push_back(edge{i, t});
        }
    }
    while(q--){
        my x, y;
        cin >> x >> y;
        cout << G[x][y].v << '\n';
    }
    return 0;
}
