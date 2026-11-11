#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
bool ST; namespace furina{
    const int N = 5e5, M = 5e2;
    const ll inf = 0x7fffffffffffffff >> 2;

    int c, n, m, d, q;
    ll w[N + 10];

    vector<pair<int, ll> > vt[N + 10];

    ll f[M + 10][M + 10];

    int main(){
        cin >> c >> n >> m >> d >> q;
        for(int i = 1; i <= m; i++)
            cin >> w[i];
        for(int i = 1, k; i <= n; i++){
            cin >> k;
            for(int j = 1, a, t; j <= k; j++)
                cin >> a >> t, vt[a].push_back({i, t});
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = i == j ? 0 : inf;

        for(int i = 1; i <= m; i++){//dm
            int sz = vt[i].size();
            for(int j = 0; j < sz; j++){
                for(int k = j + 1; k < sz; k++){
                    int x = vt[i][j].first, y = vt[i][k].first;
                    f[x][y] = f[y][x] = min(f[x][y], vt[i][j].second + vt[i][k].second);
                }
            }
        }

        //O(n^3)
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            
        while(q--){//qd^2
            int s, t;
            cin >> s >> t;
            
            if(s == t){
                cout << 0 << '\n';
                continue;
            }

            ll ans = inf;
            for(pair<int, ll> S : vt[s])
                for(pair<int, ll> T : vt[t])
                    ans = min(ans, S.second + T.second + f[S.first][T.first]);

            cout << ans + w[s] + w[t] << '\n';
        }
        return 0;
    }
} bool ED;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    furina::main();
    cerr << (1000. * clock() / CLOCKS_PER_SEC) << "ms" << '\n';
    cerr << (abs(&ST - &ED) >> 20) << "mb" << '\n';
    return 0;
}
/*
g++ -o subway subway.cpp -std=c++14 -Wall -O2 -lm -Wl,--stack=2000000000 & .\subway

g++ -o subway subway.cpp -std=c++14 -Wall -O2 -lm -Wl,--stack=2000000000
subway < subway1.in > subway.out & fc subway.out subway1.ans
subway < subway2.in > subway.out & fc subway.out subway2.ans
subway < subway3.in > subway.out & fc subway.out subway3.ans
subway < subway4.in > subway.out & fc subway.out subway4.ans
subway < subway5.in > subway.out & fc subway.out subway5.ans
subway < subway6.in > subway.out & fc subway.out subway6.ans
subway < subway7.in > subway.out & fc subway.out subway7.ans
*/