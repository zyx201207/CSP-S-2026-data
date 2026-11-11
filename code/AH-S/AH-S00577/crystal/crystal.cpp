#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Read() {
    ll x = 0; int sig = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * sig;
}
inline void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 500005;
int n;
ll m, a[N];
int main() {
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    int i, j, ans = 0; n = Read(), m = Read();
    for(i = 1; i <= n; i++) a[i] = Read();
    sort(a + 1, a + n + 1);
    for(i = j = 1; i <= n; i++) {
        while(m < 0) m += a[i] - a[j++];
        ans = max(ans, i - j + 1), m -= (a[i + 1] - a[i]) * (i - j + 1);
    }
    Write(ans), putchar('\n');
}