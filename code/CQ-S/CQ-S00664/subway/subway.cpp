#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int, int>
#define x first
#define y second
#define debug() puts("----------")
#define rd read()
#define gc getchar()
#define U(i, x, y) for(re int (i) = (x); (i) <= (y); ++ (i))
#define UU(i, x, y) for(re int (i) = (x); (i) < (y); ++ (i))
#define D(i, x, y) for(re int (i) = (x); (i) >= (y); -- (i))
#define DD(i, x, y) for(re int (i) = (x); (i) > (y); -- (i))

namespace yzqwq{
    il int read(){
        int x = 0, f = 1; char ch = gc;
        while(ch < '0' || ch > '9'){
            if(ch == '-') f = -1;
            ch = gc;
        }
        while(ch >= '0' && ch <= '9'){
            x = (x << 1) + (x << 3) + (ch ^ 48);
            ch = gc;
        }
        return x * f;
    }
    il int qmi(int a, int b, int mod){
        int res = 1;
        while(b){
            if(b & 1) res = res * a % mod;
            a = a * a % mod, b >>= 1;
        }
        return res;
    }
    il int gcd(int a, int b){
        if(!b) return a;
        return gcd(b, a % b);
    }
    mt19937 rnd(time(0));
}
using namespace yzqwq;

bool f1;
const int N = 5e5 + 10, inf = 1e18, M = 505;
int n, m, d, q;
int res[N];
int delt[N];
vector<pii> ss[M];
int spd[N], s[M][M];
int f[M][M];
vector<pii> vec[N];
bool f2;

il void solve(){
    n = rd, m = rd, d = rd, q = rd;
    U(i, 1, m) delt[i] = rd;
    U(i, 1, n){
        int k = rd;
        while(k --){
            int u = rd, t = rd;
            ss[i].emplace_back(u, t);
            vec[u].emplace_back(i, t);
        }
        // sort(ss[i].begin(), ss[i].end(), [](pii x, pii y){
            // return x.x < y.x;
        // });
    }
    U(x, 1, n){
        U(i, 1, m) spd[i] = inf;
        for(auto [i, t]: ss[x]) spd[i] = t;
        U(y, x, n){
            if(x == y){
                s[x][y] = 0;
            }
            else{
                s[x][y] = inf;
                for(auto [i, t]: ss[y]){
                    s[x][y] = min(s[x][y], spd[i] + t);
                    // if(x == 1 && y == 2){
                        // cout << i <<" "<<t<<" "<<spd[i]<<"Dsf\n";
                    // }
                }
                s[y][x] = s[x][y];
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    U(i, 1, n) U(j, 1, n) f[i][j] = s[i][j];//, cout << i << " " << j << " "<< s[i][j]<<"\n";
    U(i, 1, n) U(j, 1, n) U(k, 1, n){
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
    while(q --){
        int x = rd, y = rd;
        int res = inf;
        for(auto [i, s1]: vec[x])
        for(auto [j, s2]: vec[y]){
            // cout << i << " " << j << " " << f[i][j]<<"Dd\n";
            res = min(res, f[i][j] + s1 + s2);
        }
        cout << res + delt[x] + delt[y] << "\n";
    }
    return ;
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c = rd, t = 1; while(t --){
        solve();
    }
    return 0;
}
