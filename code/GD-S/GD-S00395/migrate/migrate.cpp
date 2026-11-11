#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 5;
int typ, T, n, a[N], d, ans;
int m, b[N], nxt[N], pre[N];

inline void MIN(int &a, int b) {a = (a < b ? a : b);}
inline void MAX(int &a, int b) {a = (a > b ? a : b);}

int c[N], cn, e[N], en;
inline bool chk(int x, int y){
    cn = en = 0; int res = 0;
    for(int i = nxt[x]; i < y; i = nxt[i]) c[++cn] = i;
    for(int i = pre[y]; i > x; i = pre[i]) e[++en] = i;
    reverse(e + 1, e + 1 + en);
    for(int i = 1; i <= cn; ++i) res += c[i] - e[i];
    return res == 1;
}

int f[N], g[N], gl[N], gr[N], fl[N], fr[N];
inline void calc(int l, int r){
    m = 0;
    // cout << l << ' ' << r << endl;
    for(int i = l; i <= r; ++i) b[++m] = a[i];
    for(int i = 1; i <= m; ++i) f[i] = g[i] = 0, gl[i] = gr[i] = fl[i] = fr[i] = -1;
    for(int i = 1, j = 1; i <= m; ++i){
        j = max(j, i);
        while(j < m && b[j + 1] - b[i] <= d) ++j;
        nxt[i] = j;
    }
    for(int i = m, j = m; i; --i){
        j = min(j, i);
        while(j > 1 && b[i] - b[j - 1] <= d) --j;
        pre[i] = j;
    }
    // for(int i = 1; i <= m; ++i)
    //     for(int j = 2; j <= m; ++j){
    //         ans += chk(i, j);
    //         if(chk(i, j)) cout << i << ' ' << j << endl;
    //     }
    // return ;
    for(int i = 1; i <= m; ++i){
        if(gl[pre[i]] == -1) gl[pre[i]] = gr[pre[i]] = i;
        else MIN(gl[pre[i]], i), MAX(gr[pre[i]], i);
        if(fl[nxt[i]] == -1) fl[nxt[i]] = fr[nxt[i]] = i;
        else MIN(fl[nxt[i]], i), MAX(fr[nxt[i]], i);
    }
    for(int i = 1; i <= m; ++i){
        if(i > 1 && nxt[pre[i]] == i) f[i] += f[pre[i]];
        if(fl[i] != -1 && pre[i] <= fr[i]) f[i] += fr[i] - max(fl[i], pre[i]) + 1;
    }
    for(int i = m; i; --i){
        if(i < m && pre[nxt[i]] == i) g[i] += g[nxt[i]];
        if(gl[i] != -1 && gl[i] <= nxt[i]) g[i] += min(nxt[i], gr[i]) - gl[i] + 1; 
    }
    // cout << fl[2] << ' ' << fr[2] << ' ' << pre[2] << endl;
    for(int i = 1; i <= m; ++i){
        int x = nxt[i], y = nxt[x];
        if(i < x && x < y){
            //ok l ok r
            if(pre[y] == x - 1 && pre[x - 1] == i) ans += f[i] * g[y];
            //no l no r
            if(x - 1 > i && pre[x - 1] <= i && gl[x - 1] != -1){
                int jl = max(x + 1, gl[x - 1]), jr = min(y, gr[x - 1]);
                if(jl <= jr) ans += jr - jl + 1;
            }
            //no l ok r
            if(x - 1 > i && pre[x - 1] <= i && pre[y] == x - 1){
                ans += g[y];
            }
        }
        //ok l no r
        x = pre[i], y = pre[x];
        if(x + 1 < i && nxt[x + 1] >= i && nxt[y] == x + 1){
            ans += f[y];
        }
    }
}
signed main(){
    // system("fc migrate6.ans migrate.out /w"); return 0;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);    
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> typ >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        ans = 0;
        int l = 1, r;
        while(l <= n){
            r = l;
            while(r < n && a[r + 1] - a[r] <= d) ++r;
            calc(l, r);
            l = r + 1;
        } 
        cout << ans << '\n';
    }
    return 0;
}