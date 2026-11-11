#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 505 , M = 5e5 + 5 , inf = 0x3f3f3f3f3f3f3f3fll;
int n , m , q , a[M] , e[N][N];
vector <pair <int , int> > v[M];
signed main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int rub;
    cin >> rub >> n >> m >> rub >> q;
    for (int i = 1;i <= m;i++) cin >> a[i];
    int x , y , z;
    for (int i = 1;i <= n;i++){
        cin >> x;
        while (x--){
            cin >> y >> z;
            v[y].push_back({i , z});
        }
    }
    memset(e , 0x3f , sizeof e);
    for (int i = 1;i <= n;i++) e[i][i] = 0;
    for (int i = 1;i <= m;i++){
        for (pair <int , int> j : v[i]){
            for (pair <int , int> k : v[i]) e[j.first][k.first] = min(e[j.first][k.first] , j.second + k.second);
        }
    }
    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++) e[i][j] = min(e[i][j] , e[i][k] + e[k][j]);
        }
    }
    while (q--){
        cin >> x >> y;
        int ans = inf;
        for (pair <int , int> i : v[x]){
            for (pair <int , int> j : v[y]) ans = min(ans , i.second + j.second + e[i.first][j.first]);
        }
        cout << ans + a[x] + a[y] << '\n';
    }
    return 0;
}