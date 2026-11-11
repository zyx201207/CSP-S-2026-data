#include <bits/stdc++.h>
#define int long long

using namespace std;

inline int read() {
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

inline void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 200005, INF = 0x3f3f3f3f;

int n, a[N];
string s;

signed main(void) {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int len = 0, ans = 0;
    bool flag = 0;
    n = read();
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
        len += a[i];
        char c;
        cin >> c;
        for (int j = 1; j <= a[i]; j ++) s += c;
    }
    string k = s;
    reverse(s.begin(), s.end());
    if (len % 2 == 0) {
        int sum = 0;
        for (int i = 0; i < len / 2; i ++) if (s[i] != k[i]) sum ++;
        ans = sum, sum = 0;
        for (int i = len / 2; i < len; i ++) if (s[i] != k[i]) sum ++;
        ans = min(ans, sum);
        write(ans);
    }
    else {
        int sum;
        for (int i = 0; i < len / 2; i ++) if (s[i] != k[i]) sum ++;
        ans = sum, sum = 0;
        for (int i = len / 2 + 1; i < len; i ++) if (s[i] != k[i]) sum ++;
        ans = min(ans, sum);
        write(ans);
    }
    return 0;
}
