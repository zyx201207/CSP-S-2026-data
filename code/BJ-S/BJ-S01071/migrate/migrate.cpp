#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int NR = 2e6 + 10;
const int KR = 5010;
int n;
ll D;
ll a[NR];
int nxt[NR], d[NR];
int f[NR];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    scanf("%d%d", &c, &T);
    while(T--) {
        scanf("%d%lld", &n, &D);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i <= n; i++) {
            nxt[i] = upper_bound(a + i, a + n + 1, a[i] + D) - a - 1;
            //printf("nxt[%d]=%d\n", i, nxt[i]);
        }
        if(c <= 10) {
            ll ans = 0;
            for(int r = 1; r <= n; r++) {
                //printf("r=%d\n", r);
                d[r] = 0;
                for(int i = r - 1; i >= 1; i--) {
                    d[i] = d[min(nxt[i], r)] + 1;
                }
                f[r] = 0;
                for(int i = r - 1; i >= 1; i--) {
                    if(nxt[i] == i) break;
                    int ne = min(nxt[i], r);
                    bool tfl = (d[ne] == d[ne - 1]);
                    if(f[ne] == 2) f[i] = 2;
                    else if(f[ne] == 1) {
                        if(tfl) f[i] = 2;
                        else f[i] = 1;
                    }
                    else {
                        if(tfl) {
                            if(f[ne - 1] > 0 || (ne - 2 > 0 && d[ne - 2] == d[ne])) f[i] = 2;
                            else f[i] = 1;
                        }
                        else f[i] = 0;
                    }
                    ans += (f[i] == 1);
                    //printf(" f[%d]=%d\n", i, f[i]);
                }
            }
            printf("%lld\n", ans);
            continue;
        }
    }
    return 0;
}

