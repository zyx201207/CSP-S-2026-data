//15:51 开始写了，根本没有这样的 CSP-S /ng/ng/ng
//16:26 大样例过了，根本没有这样的 CSP-S /ll/ll/ll 那我之前吃的那些苦算什么 /ll/ll/ll
#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline LL read(){
    LL x = 0, ff = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') c = getchar(), ff = -1;
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * ff;
}
const int N = 2.1e6;
const LL inf = 2e18;
int n, nxt[N];
LL d, a[N];
LL f[N], g[N], h[N], ans;
void init(){
    a[0] = -3e18, a[n + 1] = 3e18;
    for(int i = 1; i <= n; ++i)
        f[i] = g[i] = h[i] = 0;
    ans = 0;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int caseidd = read(), casecnt = read();
    while(casecnt --){
        // !!!   a[i + 1] - a[i] >= 0
        n = read(); d = read();
        for(int i = 1; i <= n; ++i)
            a[i] = read();
        init();
        for(int i = n, j = n; i; --i){
            while(a[j] - a[i] > d) --j;
            nxt[i] = j;
        }
        nxt[0] = 0;
        for(int i = n; i; --i){
            ans += g[nxt[i]] + h[nxt[i]];
            if(i >= 2 && nxt[i - 1] == nxt[i]){
                if(i >= 3 && nxt[i - 2] == nxt[i]){
                    ;
                }
                else{
                    g[i] += f[nxt[i]];
                }
            }
            else{
                f[i] += f[nxt[i]];
                if(i >= 2 && nxt[i - 1] == nxt[i] - 1) ;
                else h[i] += g[nxt[i]];
                // ans += g[nxt[i]];
                h[i] += h[nxt[i]];
            }
            if(i >= 2) f[i] += (nxt[i] - max(nxt[i - 1], i));
            else f[i] += (nxt[i] - i);
            if(i >= 3) g[i] += (max(nxt[i - 1], i) - max(nxt[i - 2], i));
            else if(i >= 2) g[i] += (max(nxt[i - 1], i) - i);
        }
        // for(int i = 1; i <= n; ++i)
        //     printf("%d %lld %lld %lld\n", nxt[i], f[i], g[i], h[i]);
        cout << ans << '\n';
    }
    return 0;
}
/*
g++ migrate.cpp -o migrate.exe -O2 -Wall -Wextra
./checker
*/