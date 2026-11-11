#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 600;
const int M = 6e5;
const ll inf = 1e18;
int id, n, m, d, q;
ll w[M];
vector<pair<int,ll>> xin[M];
ll g[N][N];
double Time(){
    return (double)clock()/CLOCKS_PER_SEC;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> id >> n >> m >> d >> q;
    // n xianlu
    // m zhan
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
    if(i^j) g[i][j] = inf;

    for(int i=1; i<=m; ++i) scanf("%lld", &w[i]);
    for(int i=1,k; i<=n; ++i){
        scanf("%d", &k);
        for(ll j=1,x,ti; j<=k; ++j){
            scanf("%lld %lld", &x, &ti);
            xin[x].push_back({i,ti});
        }
    }
    for(int i=1; i<=m; ++i){
        for(int j=0; j<xin[i].size(); ++j){
            int x = xin[i][j].first, y;
            for(int k=0; k<j; ++k){
                y = xin[i][k].first;
                g[x][y] = min(g[x][y], xin[i][j].second+xin[i][k].second);
                g[y][x] = g[x][y];
            }
        }
    }
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            if(i==k) continue;
            for(int j=1; j<=n; ++j){
                if(j==k || j==i) continue;
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        int x, y; scanf("%d %d", &x, &y);
        if(x==y){
            printf("0\n");
            continue;
        }ll res = inf;
        for(auto pre:xin[x]){
            for(auto now:xin[y]){
                res = min(res, pre.second+now.second+g[pre.first][now.first]);
            }
        }printf("%lld\n", res+w[x]+w[y]);
    }//cerr<<Time()<<'s'<<endl;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/