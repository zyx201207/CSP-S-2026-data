//17:08 还有一个半小时，神秘 T4 能赶完吗
//18:29 I'm loser，+了
#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
    int x = 0, ff = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') c = getchar(), ff = -1;
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * ff;
}
const int N = 2.1e6, LOGN = 23, inf = 1e8;
int n, lim, head[N], to[N * 2], nxt[N * 2], tot;
void add_edge(int x, int y){
    ++tot;
    to[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
int P, Q, dep[N], maxdep[N], fa[N];
bool flg[N];
void dfs(int x){
    dep[x] = dep[fa[x]] + 1;
    maxdep[x] = 0;
    for(int i = head[x]; i; i = nxt[i]){
        int y = to[i];
        if(y == fa[x] || flg[y]) continue;
        fa[y] = x;
        dfs(y);
        maxdep[x] = max(maxdep[x], maxdep[y] + 1);
    }
}
vector<int> v;
int LOG[N], st1[N][LOGN], st2[N][LOGN];
void init_ST(){
    LOG[1] = 0;
    for(int i = 2; i <= n; ++i) LOG[i] = LOG[i >> 1] + 1;
    for(int i = 0; i < v.size(); ++i) st1[i][0] = maxdep[v[i]] + i, st2[i][0] = maxdep[v[i]] - i;
    for(int j = 1; j <= LOG[v.size()]; ++j)
        for(int i = 0; i < v.size() - (1 << (j - 1)); ++i)
            st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]),
            st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
}
int query1(int l, int r){
    int k = LOG[r - l + 1];
    return max(st1[l][k], st1[r - (1 << k) + 1][k]);
}
int query2(int l, int r){
    int k = LOG[r - l + 1];
    return max(st2[l][k], st2[r - (1 << k) + 1][k]);
}
void init(){
    tot = 0, dep[0] = -1;
    for(int i = 1; i <= n; ++i){
        head[i] = 0, fa[i] = 0;
        dep[i] = 0, maxdep[i] = 0;
        flg[i] = 0;
    }
    v.clear();
}
int f[N], g[N], num[N];
void DFS(int x, int mid){
    num[x] = maxdep[x] < mid;
    f[x] = 1, g[x] = inf;
    for(int i = head[x]; i; i = nxt[i]){
        int y = to[i];
        if(y == fa[x] || flg[y]) continue;
        DFS(y, mid);
        f[x] += f[y];
        num[x] += num[y];
    }
    for(int i = head[x]; i; i = nxt[i]){
        int y = to[i];
        if(y == fa[x] || flg[y]) continue;
        g[x] = min(g[x], g[y] + num[x] - num[y]);
    }
    if(maxdep[x] < mid) f[x] = 0, g[x] = 0;
}
int check(int mid){
    int x = v[mid], y = v[v.size() - 1 - mid], ans = inf, F = 0, G = inf, tmp = 0;
    for(int i = mid; i <= v.size() - 1 - mid; ++i){
        DFS(v[i], mid);
        tmp += num[v[i]];
    }
    ans = tmp;
    for(int i = mid, j = mid; i < v.size() - 1 - mid; ++i){
        tmp += num[v[i]];
        int MID = (i + j + 1) >> 1;
        while(j < v.size() - 1 - mid && (i == j || max(query1(i + 1, (i + j + 1) / 2) - i, j + 1 - query2((i + j + 1) / 2 + 1, j)) <= mid)) tmp -= num[v[j ++]];
        // cerr << i << ' ' << j << ' ' << mid << ' ' << v[i] << endl;
        ans = min(tmp, ans);
    }
    return ans;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int caseidd = read(), casecnt = read();
    while(casecnt --){
        n = read(); lim = read();
        init();
        if(n == lim){
            puts("0");
            continue;
        }
        for(int i = 1; i < n; ++i){
            int x = read(), y = read();
            add_edge(x, y);
            add_edge(y, x);
        }
        // cerr << "YES" << endl;
        fa[1] = 0; dfs(1);
        P = 0;
        for(int i = 1; i <= n; ++i)
            if(dep[i] > dep[P])
                P = i;
        fa[P] = 0; dfs(P);
        Q = 0;
        for(int i = 1; i <= n; ++i)
            if(dep[i] > dep[Q])
                Q = i;
        // cerr << "YES" << P << ' ' << Q << endl;
        for(int x = Q; x; x = fa[x]){
            v.push_back(x);
            flg[x] = 1;
        }
        for(int i = 0; i < (int)v.size(); ++i){
            int x = v[i];
            fa[x] = 0;
            dfs(x);
        }
        // cerr << "YES" << endl;
        init_ST();
        // cerr << "YES" << endl;
        int l = 1, r = v.size() / 2 - 1, ans = v.size() / 2;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid) <= lim) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
g++ hub.cpp -o hub.exe -O2 -Wall -Wextra
./checker
*/