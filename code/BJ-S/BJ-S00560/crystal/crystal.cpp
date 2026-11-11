#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    static int sgn, res; sgn = 0, res = 0; static char ch = getchar();
    while(!isdigit(ch)) sgn ^= (ch == '-'), ch = getchar();
    while(isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
    return sgn ? -res : res;
}

const int N = 5e5 + 10, INF = 1e18;
int n, m, a[N], ans, lst[N], r[N], s[N], diff[N];

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++) r[i] = i;
    for(int i = 1; i <= n; i++){
        r[lst[a[i]]] = i;
        lst[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        diff[i] = (i - 1) * a[i] - s[i - 1];
    }
    int p = lower_bound(diff + 1, diff + 1 + n, m) - diff;
    if(diff[p] == m){
        cout << r[p];
        return 0;
    }
    if(p == n + 1){
        cout << n;
        return 0;
    }
    int nw = r[p - 1], sum = 0;
    while(nw >= 1 && sum + (a[p - 1] - a[nw]) <= m){
        sum += a[p - 1] - a[nw];
        nw--;
        ans++;
    }
    int nw2 = r[p], sum2 = 0, cnt = 0;
    while(nw2 >= 1 && sum2 + (a[p] - a[nw2]) <= m){
        sum2 += a[p] - a[nw2];
        nw2--;
        cnt++;
    }
    cout << max(ans, cnt) << '\n';
    return 0;
}