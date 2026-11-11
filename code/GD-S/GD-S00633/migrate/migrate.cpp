#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <queue>
using namespace std;
using ui32 = unsigned int;
using big = long long;
using ui64 = unsigned big;
using bigf = long double;
constexpr const big INF = 1e18;
constexpr const big mod = 998244353;
constexpr const bigf EPS = 1e-8;

constexpr const int N = 2e6 +5;

void solve() {

}

big x[N], n, d;
big sum[N], disL[N], dis[N], ans;
void solve1() {
    cin>>n>>d; ans = 0;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int r=2;r<=n;r++) {
        sum[r+1] = 0;
        dis[r] = 0, sum[r] = 1, disL[0] = r;
        for(int i=r-1,rp=r;i>=1;i--) {
            while(rp>i&&x[rp]-x[i]>d) rp--;
            if(rp==i) break;
            dis[i] = dis[rp]+1, disL[dis[i]] = i;
            big now = sum[disL[dis[rp]]] - sum[rp+1];
            if(now==2) ans++;
            sum[i] = sum[i+1] + now;
        }
    }
    cout<<ans<<"\n";
}
// 40pts

void solve2() {
    cin>>n>>d; ans = 0;
    for(int i=1;i<=n;i++) cin>>x[i];
    if(n==1) {
        cout<<"0\n";
        return;
    }
    big k = d/(x[2]-x[1]);
    if(k<=1) {
        cout<<"0\n";
        return;
    }
    big expdis = 2*k-1;
    cout<<max(n-expdis,0LL)<<"\n";
}
// 8pts

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int c, t; cin >> c >> t;
    while (t--) {
        if(c<=10) solve1();
        else if(c<=12) solve2();
        else solve();
    }
    return 0;
}
