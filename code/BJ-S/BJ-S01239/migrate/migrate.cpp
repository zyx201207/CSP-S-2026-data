#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 5005;
int c, t, n;
ll a[N], d;
void solve() {
    int cnt = 0;
    scanf("%d %lld", &n, &d);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            ll dis = a[j] - a[i];
            if(dis >= (d << 1)) break;
            if(dis <= d) continue;
            ll l = a[j] - d, r = a[i] + d;
            int sc = 0;
            for(int k = i + 1; k < j; k++) if(a[k] >= l && a[k] <= r) sc++;
            if(sc == 2) cnt++;
        }
    }
    printf("%d\n", cnt);
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--) solve();
    return 0;
}
