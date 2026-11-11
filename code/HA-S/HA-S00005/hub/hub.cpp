#include <cstdio>

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

#include <queue>
#include <cstring>

const int MAXN = 2e6 + 10;

struct EDGE {
    int v, next;
} edge[MAXN << 1];

int head[MAXN], edgeNum;
void AddEdge(int u, int v) {
    edge[++edgeNum] = {v, head[u]};
    head[u] = edgeNum;
}

int c, t;
int n, k;
int choose[MAXN];
int vis[MAXN];

void dfs(int u, int fa) {
    vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa || !choose[v]) continue;
        dfs(v, u);
    }
}

int dis[MAXN];

void BFS() {
    std::queue<int> q;
    memset(dis, 0x3f, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; ++i) if (choose[i]) {
        q.push(i);
        dis[i] = 0;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

void Sol1() {
    int ans = 0x7fffffff;
    for (int mask = 0; mask < 1 << n; ++mask) if (__builtin_popcount(mask) == k) {
        for (int i = 1; i <= n; ++i) {
            if (mask >> (i - 1) & 1) choose[i] = 1;
            else choose[i] = 0;
        }
        
        memset(vis, 0, sizeof(int) * (n + 1));
        int cnt = 0;
        for (int i = 1; i <= n; ++i) if (choose[i] && !vis[i]) {
            ++cnt;
            dfs(i, 0);
        }
        
        if (cnt > 2) continue;
        
        BFS();
        
//        fprintf(stderr, "choose:");
//        for (int i = 1; i <= n; ++i) if (choose[i]) fprintf(stderr, " %d", i);
//        fprintf(stderr, "\n");
//        for (int i = 1; i <= n; ++i) fprintf(stderr, "dis[%d]=%d\n", i, dis[i]);
        
        
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (dis[i] > res) res = dis[i];
        }
        
//        fprintf(stderr, "res=%d\n", res);
        
        if (res < ans) ans = res;
    }
    printf("%d\n", ans);
}

void Work() {
    n = io.read<int>(), k = io.read<int>();
    for (int i = 1; i <= n - 1; ++i) {
        int u = io.read<int>(), v = io.read<int>();
        AddEdge(u, v);
        AddEdge(v, u);
    }
    
    if (1 <= c && c <= 3) {
        Sol1();
    } else {
        Sol1();
    }
    
    memset(head, 0, sizeof(int) * (n + 1));
    edgeNum = 0;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    c = io.read<int>(), t = io.read<int>();
//    fprintf(stderr, "[%d, %d]\n", c, t);
    while (t--) {
        Work();
    }
}
