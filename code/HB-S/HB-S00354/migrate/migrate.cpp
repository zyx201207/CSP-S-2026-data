#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
constexpr int N = 1e6+10;
int n, x[N], nxt[N];
int d;
void solve(){
    scanf("%lld%lld", &n, &d);
    for(int i = 1; i <= n; ++i) scanf("%lld", x+i);
    printf("%lld\n", n*(n-1)/2);
    return;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, k;
    scanf("%lld%lld", &c, &k);
    while(k--) solve();
    return 0;
}
