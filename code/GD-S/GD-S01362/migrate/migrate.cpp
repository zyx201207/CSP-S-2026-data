#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define pb push_back
#define mst(f, i) memset(f, i, sizeof f)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
namespace fastio{
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = getchar();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = getchar();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args &...args){
        read(t), read(args...);
    }
    void write(int x){printf("%d", x);}
    void writes(int x){printf("%d ", x);}
    void writeln(int x){printf("%d\n", x);}
    void write(ll x){printf("%lld", x);}
    void writes(ll x){printf("%lld ", x);}
    void writeln(ll x){printf("%lld\n", x);}
}
using namespace fastio;
#define multitest() int T; read(T); _rep(tCase, 1, T)
const int N = 2e6 + 5;
int tid;
ll n, d, ans, a[N];
int nxt[N];
ll dp[N][4];// 1 | (>=2) 1 | __ 1 1 | __ 2
void clr(){
    _rep(i, 0, n + 1) dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 0, nxt[i] = 0;
    ans = 0;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    read(tid);
    multitest(){
        read(n, d);
        _rep(i, 1, n) read(a[i]);
        int j = n;
        _req(i, n, 1){
            while(a[j] - a[i] > d) j--;
            nxt[i] = j;
        }
        _rep(i, 1, n){
            dp[i][0]++;
            int j = nxt[i]; 
            if(j == i) continue;
            if(dp[i][0]){
                if(j == i + 1) dp[j][0] += dp[i][0];
                else dp[j][2] += dp[i][0];
            }
            if(dp[i][1]){
                if(nxt[i] == nxt[i - 1] + 1) dp[j][1] += dp[i][1];
                if(nxt[i] > nxt[i - 1] + 1) dp[j][2] += dp[i][1];
            }
            if(dp[i][2]){
                int x = nxt[i - 1], y = nxt[i - 2];
                ans += dp[i][2] * (x - y);
                if(x == j && y < x) dp[j][3] += dp[i][2];
                if(x == j - 1){
                    if(x == i) dp[j][0] += dp[i][2];
                    else dp[j][1] += dp[i][2];
                }
                if(x < j - 1) dp[j][2] += dp[i][2];
            }
            if(dp[i][3]){
                int x = nxt[i - 1];
                if(x < j){
                    ans += 1ll * dp[i][3] * (j - x);
                    dp[j][3] += dp[i][3];
                }
            }
        }
        writeln(ans);
        clr();
    }
    return 0;
}