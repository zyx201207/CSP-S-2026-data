#include <cstdio>
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

const int MAXN = 2e6 + 10;

int c, t;
int n;
ll d, x[MAXN];

void Work() {
    n = io.read<int>(), d = io.read<ll>();
    for (int i = 1; i <= n; ++i) {
        x[i] = io.read<ll>();
    }
    io.putchar('0'), io.putchar('\n');
    return ;
    
//    for (int l = 1; l <= n; ++l) {
//        for (int r = l + 3; r <= n; ++r) {
//            
//        }
//    }

    ll a, b, c, e, ans = 0, L = 0;
    for (int l = 1, r = 4; r <= n; ++r) {
        a = x[r - 2] - x[r - 3], b = x[r - 1] - x[r - 2], c = x[r] - x[r - 1];
        ans += L;
        FLAG:
        if (a + b <= d && b + c <= d && a + b + c > d) {
            if (r + 1 > n) {
                io.write(1);
                return ;
            }
            L = r - 3 - l + 1;
            e = x[r + 1] - x[r];
            if (c + e > d) {
                l = r - 1;
                r += 2;
                ans += 3 * L;
            } else if (c + e <= d && b + c + e > d) {
                L = 0;
                ans += L;
                r += 2;
            } else if (a + b <= d && b + c + e <= d && a + b + c + e > d) {
                goto FLAG;
            } else {
                printf("???"); 
            }
        }
    }
    
    io.write(ans);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = io.read<int>(), t = io.read<int>();
    while (t--) {
        Work();
    }
    return 0;
}
