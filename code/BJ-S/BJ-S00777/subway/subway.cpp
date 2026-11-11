#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int c , n , m , d , q;
int w[N] ,  k[510];
ll dis[510][510];
struct Station {
    int num , id , t; // 第num条线路上的第id站，转站时间t
};
vector <Station> a[N];
signed main() {
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++) {
            int x , t;
            cin >> x >> t;
            a[x].push_back(Station{i , j , t});
        }
    }
    memset(dis , 0x3f , sizeof(dis));
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= m;i++) {
        for(auto [x , idx , tx] : a[i]) {
            for(auto [y , idy , ty] : a[i]) {
                if(x == y) continue;
                dis[x][y] = min(dis[x][y] , tx + ty);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            for(int k = 1;k <= n;k++) {
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }
    // for(int i = 1;i <= n;i++) {
    //     for(int j = 1;j <= n;j++) {
    //         cout << dis[i][j] << "(" << i << ", " << j << ")   ";
    //     }
    //     cout << endl;
    // }
    while(q--) {
        int s , t;
        ll ans = 9e18;
        cin >> s >> t;
        for(auto [x , idx , tx] : a[s]) {
            for(auto [y , idy , ty] : a[t]) {
                ans = min(ans , tx + ty + dis[x][y]);
            }
        }
        cout << ans + w[s] + w[t] << endl;
    }
    return 0;
}