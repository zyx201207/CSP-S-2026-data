#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<assert.h>
#include<ctime>
#include<vector>
// #define int long long
typedef long long LL;
#define PII pair<int, int>
using namespace std;
bool st_m;
namespace Read{
    inline int read(){
        int f = 0, d = 1; char op;
        while(op = getchar(), !isdigit(op)) if(op == '-') d = - 1;
        while(isdigit(op)) f = (f << 1) + (f << 3) + (op ^ 48), op = getchar();
        return f * d;
    }
} using namespace Read;
namespace Bule13{
    const int N = 510, M = 5e5 + 10; LL INF = 0x3f3f3f3f3f3f3f3f;
    int n, m, maxx, t;
    int none[M];
    LL d[N][N];
    vector<PII> v[M];
    signed main(){
        read(), n = read(), m = read(), maxx = read(), t = read();
        for(int i = 1; i <= m; i ++ ) none[i] = read();
        for(int i = 1; i <= n; i ++ ){
            int x = read(), y, z;
            while(x -- ){
                y = read(), z = read(); v[y].push_back({i, z});
            }
        }
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                if(i != j) d[i][j] = INF;
            }
        }
        for(int i = 1; i <= m; i ++ ){
            for(int j = 0; j < (int)v[i].size(); j ++ ){
                for(int k = 0; k < (int)v[i].size(); k ++ ){
                    if(j != k) d[v[i][j].first][v[i][k].first] = min(d[v[i][j].first][v[i][k].first], 0ll + v[i][j].second + v[i][k].second);
                }
            }
        }
        for(int k = 1; k <= n; k ++ ){
            for(int i = 1; i <= n; i ++ ){
                for(int j = 1; j <= n; j ++ ){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int x, y;
        while(t -- ){
            x = read(), y = read();
            LL ans = INF;
            for(int i = 0; i < (int)v[x].size(); i ++ ){
                for(int j = 0; j < (int)v[y].size(); j ++ ){
                    ans = min(ans, d[v[x][i].first][v[y][j].first] + v[x][i].second + v[y][j].second);
                }
            }
            ans += none[x] + none[y];
            cout<<ans<<'\n';
        }
        return 0;
    }
}
bool ed_m;
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    Bule13::main();
    // cerr<<"time:"<<(double)clock() / CLOCKS_PER_SEC<<"\nmemory:"<<(&st_m - &ed_m) / 1024.0 / 1024.0<<'\n';
    return 0;
}
/*
g++ subway.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\a.exe < a.in > a.out

fc subway.out subway.ans

g++ subway.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\a.exe < subway\subway1.in > a.out && fc a.out subway\subway1.ans
.\a.exe < subway\subway2.in > a.out && fc a.out subway\subway2.ans
.\a.exe < subway\subway3.in > a.out && fc a.out subway\subway3.ans
.\a.exe < subway\subway4.in > a.out && fc a.out subway\subway4.ans
.\a.exe < subway\subway5.in > a.out && fc a.out subway\subway5.ans
.\a.exe < subway\subway6.in > a.out && fc a.out subway\subway6.ans
.\a.exe < subway\subway7.in > a.out && fc a.out subway\subway7.ans

finish:14:54

*/