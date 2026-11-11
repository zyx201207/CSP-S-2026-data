#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
#define int long long
#define rep(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define per(i, a, b) for(int i = (b) ; i >= (a) ; i--)
int c, t;
constexpr int N = 2e6 + 10;
void read(int &x){
    x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        f = (ch == '-' ? -1 : 1), ch = getchar();
    while(ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x *= f;
}
int n, d, a[N];
int R[N], L[N];
int cntpre[N], cntnxt[N];
int mx[N], mn[N];
int cntL[N], cntR[N];
static inline void chkmin(int &x, int y){
    if(y < x)
        x = y;
}
static inline void chkmax(int &x, int y){
    if(y > x)
        x = y;
}
void solve(){
    read(n), read(d);
    rep(i, 1, n){
        read(a[i]);
        cntpre[i] = cntnxt[i] = 0;
        mn[i] = n + 1, mx[i] = 0;
        cntL[i] = cntR[i] = 0;
    }
    {
        int r = 1;
        rep(i, 1, n){
            while(r < n && a[r + 1] - a[i] <= d)
                r++;
            R[i] = r;
            chkmin(mn[R[i]], i);
            cntR[R[i]]++;
        }
        int l = n;
        per(i, 1, n){
            while(l > 1 && a[i] - a[l - 1] <= d)
                l--;
            L[i] = l;
            chkmax(mx[L[i]], i);
            cntL[L[i]]++;
        }
    }
    rep(i, 1, n){
        if(L[i] != i && R[L[i]] > i)
            cntnxt[L[i]]++;
        if(R[i] != i && L[R[i]] < i)
            cntpre[R[i]]++;
    }
    per(i, 1, n){
        if(R[i] != i && L[R[i]] == i)
            cntnxt[i] += cntnxt[R[i]] + 1;
    }
    rep(i, 1, n){
        if(L[i] != i && R[L[i]] == i)
            cntpre[i] += cntpre[L[i]] + 1;
    }
    int ans = 0;
    rep(i, 1, n - 1){
        if(mx[i] <= i + 1 || mn[i + 1] >= i) continue;
        int ll = cntR[i + 1], rr = cntL[i];
        if(L[i] == mn[i + 1]) ll += cntpre[mn[i + 1]];
        if(R[i + 1] == mx[i]) rr += cntnxt[mx[i]];
        ans += ll * rr;
    }
    printf("%lld\n", ans);
}
signed main(){
    #ifndef DEBUG
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    #endif 
    read(c), read(t);
    while(t--)
        solve();
    return 0;
}