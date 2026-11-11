#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
typedef long long ll;

struct IO {
    static const int BUFSIZE = 1 << 20;
    char buf[BUFSIZE], *p1, *p2;
    char pbuf[BUFSIZE], *pp;
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
    
    char getchar() {
        if (p1 == p2) {
            p2 = (p1 = buf) + fread(buf, 1, BUFSIZE, stdin);
            if (p1 == p2) return EOF;
        }
        return *p1++;
    }
    
    void putchar(char ch) {
        if (pp - pbuf == BUFSIZE) {
            fwrite(pbuf, 1, BUFSIZE, stdout);
            pp = pbuf;
        }
        *pp++ = ch;
    }
    
    bool isdigit(char ch) {
        return '0' <= ch && ch <= '9';
    }
    
    template <typename T> T read() {
        T res = 0, f = 1;
        char ch = getchar();
        for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
        for (; isdigit(ch); ch = getchar()) res = (res << 3) + (res << 1) + (ch ^ 48);
        return res * f;
    }
    
    template <typename T> void write(T x, char ed = '\n') {
        if (x < 0) x = -x, putchar('-');
        int sta[sizeof(T) << 2], top = 0;
        do {
            sta[++top] = x % 10;
            x /= 10;
        } while (x);
        while (top) {
            putchar(sta[top--] ^ 48);
        }
        putchar(ed);
    }
} io;

const int MAXN = 510;
const int MAXM = 5e5 + 10;
const int MAXQ = 1e5 + 10;

void chkmin(ll &a, ll b) {
    if (a > b) a = b;
}

int c, n, m, d, q;
int k[MAXN];
ll w[MAXM];
std::vector<int> a[MAXN];
__gnu_pbds::gp_hash_table<int, ll> t[MAXN];
int x[MAXQ], y[MAXQ];
ll ans[MAXQ];
std::vector<std::pair<int, int>> g[MAXM];

void AddEdge(int u, int v, int id) {
    g[u].emplace_back(v, id);
    g[v].emplace_back(u, id);
}

struct ITEM {
    ll time;
    int u;
    int sid;
    int fa;
    ITEM(ll time, int u, int sid, int fa) : time(time), u(u), sid(sid), fa(fa) {}
};

/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
*/

void Work1() {
    for (int _ = 1; _ <= q; ++_) {
        std::queue<ITEM> que;
        que.emplace(0, x[_], 0, 0);
        while (!que.empty()) {
            ll time = que.front().time; int u = que.front().u, sid = que.front().sid, fa = que.front().fa;
            que.pop();
//            printf("[%lld, %d, %d, %d]\n", time, u, sid, fa);
            if (u == y[_]) {
                chkmin(ans[_], time + t[sid][u]);
                continue;
            }
            for (auto e : g[u]) {
                int v = e.first, vid = e.second;
                if (v == fa) continue;
                if (sid == vid) {
                    que.emplace(time, v, vid, u);
                } else {
//                    printf("at %d from %d to %d, cost %lld + %lld\n", u, sid, vid, t[sid][u], t[vid][u]);
                    que.emplace(time + t[sid][u] + t[vid][u], v, vid, u);
                }
            }
        }
        io.write(ans[_] + w[x[_]] + w[y[_]]);
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = io.read<int>(), n = io.read<int>(), m = io.read<int>(), d = io.read<int>(), q = io.read<int>();
    for (int i = 1; i <= m; ++i) w[i] = io.read<ll>();
    a[0].resize(m + 1);
    for (int i = 1; i <= n; ++i) {
        k[i] = io.read<int>();
        a[i].resize(k[i] + 1);
        for (int j = 1; j <= k[i]; ++j) {
            a[i][j] = io.read<int>(), t[i][a[i][j]] = io.read<ll>();
            if (j > 1) AddEdge(a[i][j], a[i][j - 1], i);
        }
    }
    for (int i = 1; i <= q; ++i) {
        x[i] = io.read<int>(), y[i] = io.read<int>();
        ans[i] = 0x7fffffffffffffff;
    }
    
    if (0 <= c && c <= 8) {
        Work1();
    } else {
        Work1();
    }
    return 0;
}
