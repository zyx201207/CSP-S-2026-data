#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], cnt[M], st[N], tt = 0, ti[M];
void solve(int p) {
    memset(st, 0, sizeof(st));
    memset(ti, 0, sizeof(ti));
    tt = 0;
    for(int i = p; i <= n; i++) {
        if(!ti[a[i]]) {
            st[++tt] = a[i];
            ti[a[i]] = tt;
        } else {
            int old = tt;
            tt = ti[a[i]];
            if(old < tt) swap(old, tt);
            for(int j = tt + 1; j <= old; j++) ti[st[j]] = 0;
        }
    }
    for(int i = 1; i <= tt; i++) cnt[st[i]]++;
    return;
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) solve(i);
    for(int i = 1; i <= m; i++) printf("%d ", cnt[i]);
    return 0;
}
//wow
//i hope my code is on the "mi huo xing wei da shang"
/*
x x xxx
o o ooo
xx x xxx
oo o ooo
xx x xxxx
oo o oooo
xx xx xx xxx
oo oo oo ooo
x x x
o o o
xx x x
oo o o
xxx xxx
ooo ooo
xxxxx
ooooo
xxxxxx
oooooo
xxx xx
ooo oo
xx oo
xx oo
xx oo
xx oo
xoxoxoxoxoxoxoxo......
music crystal zha le
*/
