// m jiedian n xianlu
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long longlong;
typedef unsigned long long ulonglong;
typedef long double ldouble;
#define int longlong
#define uint ulonglong
#define double ldouble
using namespace std;

const int N = 505, M = 5e5 + 5;
int c, n, m, d, q;
int a[M], dis[N][N];

struct node1{
    int a, t;
}; vector<node1> v1[N];

inline bool operator<(node1 p, node1 q){
    return p.a < q.a;
}

struct node2{
    int id, t;
}; vector<node2> v2[M];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        for (int j = 1; j <= k; j++){
            int x, y; cin >> x >> y;
            v1[i].push_back({x, y});
            v2[x].push_back({i, y});
        }
        sort(v1[i].begin(), v1[i].end());
    }
    for (int i = 1; i <= n; i++){
        if (v1[i].size() == 1){
            continue;
        }
        for (int j = i + 1; j <= n; j++){
            if (v1[j].size() == 1){
                continue;
            }
            int res = 4e18;
            for (int x = 0, y = 0; x < v1[i].size(); x++){
                while (y + 1 < v1[j].size() && v1[j][y].a < v1[i][x].a){
                    y++;
                }
                if (v1[i][x].a == v1[j][y].a){
                    res = min(res, v1[i][x].t + v1[j][y].t);
                }
                if (y + 1 == v1[j].size()){
                    break;
                }
            }
            dis[i][j] = dis[j][i] = res;
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            if (i == k){
                continue;
            }
            for (int j = 1; j <= n; j++){
                if (j == k){
                    continue;
                }
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--){
        int x, y; cin >> x >> y;
        int ans = 9e18;
        for (int i = 0; i < v2[x].size(); i++){
            for (int j = 0; j < v2[y].size(); j++){
                ans = min(ans, dis[v2[x][i].id][v2[y][j].id] + v2[x][i].t + v2[y][j].t);
            }
        }
        cout << ans + a[x] + a[y] << "\n";
    }
    return 0;
}