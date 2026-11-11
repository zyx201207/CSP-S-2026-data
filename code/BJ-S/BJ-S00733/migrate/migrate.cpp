#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 5000;

int n;
long long d;
long long a[N + 5];

long long fr() {
    long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

int bel[N + 5];
long long f[N + 5], sm[N + 5];
struct nod {
    long long v;
    int id;
};
queue <nod> Q;

int work() {
    n = fr();
    d = fr();
    for (int i = 1; i <= n; i++) {
        a[i] = fr();
    }
    long long ans = 0;
    for (int st = 1; st <= n; st++) {
        //printf("start from %d,\n", st);
        int lst = st, now = 1;
        memset(sm, 0, sizeof sm);
        memset(f, 0, sizeof f);
        bel[st] = 0;
        sm[0] = 1;
        while (!Q.empty()) Q.pop();
        Q.push({1, st});
        for (int i = st + 1; i <= n; i++) {
            if (a[i] - a[i - 1] > d) break;
            if (a[i] - a[lst] > d) {
                now++;
                lst = i - 1;
            }
            bel[i] = now;
            while (!Q.empty() && (a[i] - a[Q.front().id] > d && bel[Q.front().id] != now)) {
                sm[bel[Q.front().id]] -= f[Q.front().id];
                Q.pop();
            }
            f[i] = sm[bel[i] - 1];
            sm[bel[i]] += f[i];
            Q.push({f[i], i});
        }
        /*printf("bel[]: ");
        for (int i = st; i <= n; i++) {
            printf("%d, ", bel[i]);
        }
        printf("f[]: ");
        for (int i = st; i <= n; i++) {
            printf("%d, ", f[i]);
        }*/
        long long cnt = 0;
        for (int i = st + 1; i <= n; i++) {
            if (f[i] == 2) cnt++;
        }
        ans += cnt;
    }
    printf("%lld\n", ans);
    return 0;
}

int main() {
    //if (false) {
        freopen("migrate.in", "r", stdin);
        freopen("migrate.out", "w", stdout);
    //}
    int c, t;
    c = fr();
    t = fr();
    while (t--) {
        work();
    }
    return 0;
}
