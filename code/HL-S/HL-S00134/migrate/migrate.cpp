#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define int long long
int x[2000006], nxt[2000006], fst[2000006], val1[2000006], val2[2000006], bucket[2000006], ddl[2000006], to_ddl[2000006];
bool inq[2000006];
queue<signed> stac[2000006];
inline void del(int i) {
    // printf("del %lld\n", i);
    // printf("stac[%lld] %lld\n", nxt[i], stac[nxt[i]].empty() ? 0 : *(stac[nxt[i]].rbegin()));
    bucket[nxt[i]]--;
    stac[nxt[i]].pop();
    // printf("stac[%lld] %lld\n", nxt[i], stac[nxt[i]].empty() ? 0 : *(stac[nxt[i]].rbegin()));
    inq[i] = 0;
}
inline void add(int i) {
    // printf("add %lld\n", i);
    bucket[nxt[i]]++;
    // printf("stac[%lld] %lld\n", nxt[i], stac[nxt[i]].empty() ? 0 : *(stac[nxt[i]].rbegin()));
    stac[nxt[i]].push(i);
    inq[i] = 1;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int c, t; cin >> c >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> x[i];
        memset(inq, 0, sizeof(inq));
        memset(bucket, 0, sizeof(bucket));
        ddl[n] = n;
        for (int l = n, r = n; l != 0; l--) {
            // puts("aaaa");
            stac[l] = queue<signed>();
            fst[l] = val1[l] = val2[l] = 0; to_ddl[l] = ddl[l] = l;
            // printf("[%lld, %lld] -> \n", l, r);
            while (x[r] > x[l] + d) {
                if (inq[r]) del(r);
                r--;
            }
            if (inq[r]) del(r);
            // printf("[%lld, %lld]\n", l, r);
            nxt[l] = r;
            int nxtr = nxt[r];
            // ddl: last able, including
            if (bucket[nxtr] >= 2) {
                // printf("more than one(%lld) goto nxtr = %lld, ddl = %lld\n", bucket[nxtr], nxtr, r);
                ddl[l] = r;
                to_ddl[l] = to_ddl[r];
            }
            else {
                // printf("ddl = %lld\n", ddl[r]);
                ddl[l] = ddl[r];
            }
            if (bucket[nxtr] == 1) {
                fst[l] = stac[nxtr].front();
                // printf("new fst = %lld\n", fst[l]);
                ddl[l] = to_ddl[r];
                // printf("update ddl = %lld\n", to_ddl[r]);
                to_ddl[l] = r;
            }
            if (bucket[nxtr] == 0) {
                // printf("fst = %lld\n", fst[r]);
                fst[l] = fst[r];
                // printf("get val2 from %lld: %lld\n", r, val2[r]);
                val2[l] += val2[r];
                to_ddl[l] = to_ddl[r];
            }
            // calc delta val2
            if (r - 1 > l) {
                if (r - 2 > l) {
                    // printf("val2 additionally added [%lld + 1, %lld]\n", nxt[r - 2], nxt[r - 1]);
                    val2[l] += nxt[r - 1] - nxt[r - 2];
                }
                else {
                    // printf("val2 additionally added [%lld(r) + 1, %lld]\n", r, nxt[r - 1]);
                    val2[l] += nxt[r - 1] - r;
                }
            }
            if (fst[l]) val1[l] = ddl[l] - nxt[fst[l]];
            // printf("val1 = %lld, val2 = %lld\n", val1[l], val2[l]);
            ans += val1[l] + val2[l];
            add(l);
        }
        cout << ans << '\n';
    }
}