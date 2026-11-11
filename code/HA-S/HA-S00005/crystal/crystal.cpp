#include <cstdio>
#include <algorithm>
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

int n; ll m;
ll a[500010];
ll ans;

void chkmax(ll &a, ll b) { if (a < b) a = b; }

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = io.read<int>(), m = io.read<ll>();
    for (int i = 1; i <= n; ++i) {
        a[i] = io.read<ll>();
    }
    std::sort(a + 1, a + n + 1);
    
    ll needs = 0, cnt = 0;
    for (int p1 = 1, p2 = 1; p2 <= n; ++p2) {
        needs += (p2 - p1) * (a[p2] - a[p2 - 1]);
        while (needs > m) needs -= a[p2] - a[p1++], cnt--;
        chkmax(ans, ++cnt);
    }
    
    io.write(ans);
    return 0;
}
