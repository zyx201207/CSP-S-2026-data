#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define pb push_back
#define mst(f, i) memset(f, i, sizeof f)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
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
const int N = 5e5 + 5;
ll n, m, a[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    read(n, m);
    _rep(i, 1, n) read(a[i]);
    sort(a + 1, a + 1 + n);
    int j = 1, ans = 0;
    ll cur = 0;
    _rep(i, 1, n){
        cur += a[i];
        while(1ll * (i - j + 1) * a[i] - cur > m) cur -= a[j++];
        ans = max(ans, i - j + 1);
    }    
    writeln(ans);
    return 0;
}