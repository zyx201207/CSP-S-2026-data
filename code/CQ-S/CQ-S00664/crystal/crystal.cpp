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

const int N = 1e6 + 10;
int n, a[N], m, s[N];

il void solve(){
    n = rd, m = rd;
    U(i, 1, n) a[i] = rd;
    sort(a + 1, a + n + 1);
    int mx = 0;
    U(i, 1, n) s[i] = s[i - 1] + a[i];
    U(i, 1, n){
        int l = 1, r = i, w = -1;
        while(l <= r){
            int mid = l + r >> 1;
            int spd = mid * a[i] - (s[i] - s[i - mid]);
            if(spd <= m) w = mid, l = mid + 1;
            else r = mid - 1;
        }
        mx = max(mx, w);
    }
    cout << mx;
    return ;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int c = 1, t = 1; while(t --){
        solve();
    }
    return 0;
}