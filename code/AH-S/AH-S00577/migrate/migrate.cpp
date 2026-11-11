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
const int N = 2000005;
int n, cnt[N], l[N], r[N], f[2][2][N];
ll d, x[N];
void Solve() {
    int i, j, k; ll ans = 0; n = Read(), d = Read();
    for(i = 1; i <= n; i++) {
        x[i] = Read(), cnt[i] = 0;
        for(j = 0; j < 2; j++) for(k = 0; k < 2; k++) f[j][k][i] = 0;
    }
    for(i = j = 1; i <= n; i++) {
        while(x[i] - x[j] > d) j++;
        l[i] = j, cnt[j] += j < i;
    }
    for(i = j = n; i; i--) {
        while(x[j] - x[i] > d) j--;
        r[i] = j;
    }
    for(i = 1; i <= n; i++) {
        if(r[i] == i) continue;
        int t = r[i]; f[0][0][i]++, ans += 1ll * (f[0][1][i] + f[1][1][i]) * cnt[t];
        if(t > i + 1) ans += 1ll * f[0][0][i] * cnt[t - 1];
        if(r[t] == t || (t > i + 2 && r[t - 2] == r[t])) continue;
        if(r[t] == t + 1) {
            if(r[i] == i + 1) f[0][0][t] += f[0][0][i], f[0][1][t] += f[0][1][i];
            else if(r[t - 1] == r[t]) f[0][1][t] += f[0][0][i];
            else f[0][0][t] += f[0][0][i] + f[1][0][i], f[0][1][t] += f[0][1][i] + f[1][1][i];
        }
        else {
            if(r[i] == i + 1) f[0][0][t] += f[0][0][i], f[1][1][t] += f[0][1][i];
            else if(r[t - 1] == r[t]) f[1][1][t] += f[0][0][i];
            else if(r[t - 1] == r[t] - 1) f[1][0][t] += f[0][0][i] + f[1][0][i], f[1][1][t] += f[0][1][i] + f[1][1][i];
            else f[0][0][t] += f[0][0][i] + f[1][0][i], f[1][1][t] += f[0][1][i] + f[1][1][i];
        }
    }
    Write(ans), putchar('\n');
}
int main() {
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    int c = Read(), T = Read();
    while(T--) Solve();
}