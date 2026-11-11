#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void rd(ll &rs){
    rs = 0; char ch = getchar(); bool ng = false;
    while(ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if(ch == '-'){ ng = true; ch = getchar(); }
    while('0' <= ch && ch <= '9'){
        rs = (rs << 1) + (rs << 3) + ch - '0'; ch = getchar();
    }
    if(ng) rs = -rs;
}

inline void rd(int &rs){
    rs = 0; char ch = getchar(); bool ng = false;
    while(ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if(ch == '-'){ ng = true; ch = getchar(); }
    while('0' <= ch && ch <= '9'){
        rs = (rs << 1) + (rs << 3) + ch - '0'; ch = getchar();
    }
    if(ng) rs = -rs;
}

const int xn = 505, xm = 500005;
int c, n, m, d, q, cnt[xm]; ll w[xm], sb[xm][22][2], dis[xn][xn];

int main(){
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    rd(c); rd(n); rd(m); rd(d); rd(q);
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; ++i) dis[i][i] = 0;
    for(int i = 1; i <= m; ++i) rd(w[i]);
    for(int i = 1; i <= n; ++i){
        ll k; rd(k);
        for(int j = 1; j <= k; ++j){
            int a; ll t; rd(a); rd(t); sb[a][++cnt[a]][0] = (ll)i; sb[a][cnt[a]][1] = t;
        }
    }
//    for(int i = 1; i <= m; ++i, putchar(012))
 //       for(int j = 1; j <= cnt[i]; ++j) printf("%lld %lld  ", sb[i][j][0], sb[i][j][1]);
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j < cnt[i]; ++j){
            ll j1 = sb[i][j][0], j2 = sb[i][j][1];
            for(int k = j + 1; k <= cnt[i]; ++k){
                ll k1 = sb[i][k][0], k2 = sb[i][k][1];
                dis[j1][k1] = dis[k1][j1] = j2 + k2;
            }
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i < n; ++i)
            for(int j = i + 1; j <= n; ++j){
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
    }
//    for(int i = 1; i <= n; ++i, putchar(012))
//    for(int j = 1;j <= n; ++j) printf("%lld ", dis[i][j]);
 //   puts("good");
    while(q--){
        int a, b; rd(a); rd(b);
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1; i <= cnt[a]; ++i)
            for(int j = 1; j <= cnt[b]; ++j){
            ans = min(ans, dis[sb[a][i][0]][sb[b][j][0]] + sb[a][i][1] + sb[b][j][1]);
 //           printf("%lld -> %lld %lld\n", sb[a][i][1], sb[b][j][1], ans);
            }
        printf("%lld\n", ans + w[a] + w[b]);
    }
    return 0;
}
