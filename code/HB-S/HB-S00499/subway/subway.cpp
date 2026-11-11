#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);

    int c , n , m , d , q;
    int w[500009] = {} , k[509] = {} , a , t[509][500009] = {} , x , y;
    vector<pair<int , int>> v[500009];
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= n;i++){
            cin >> a >> t[i][j];
            v[i].push_back({j , a});
            v[j].push_back({i , a});
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> x >> y;
        cout << v[x][y].second;
    }
    return 0;
}
