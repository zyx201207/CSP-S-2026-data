#include <bits/stdc++.h>
using namespace std;

int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || '9' < c){
        if(c == '-') f = -1;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
    return f * x;
}

const int N = 5e5 + 5, M = 1e6 + 5, INF = 1e9;
int n, m;
int a[N], l[N];
int Din[N];
vector <int> g[N];

int f[N], ans[N];
void dfs(int u, int fa){
    f[u] = 1;
    for(auto v : g[u]){
        dfs(v, u);
        f[u] += f[v];
    }
    if(a[u] != a[fa]){
        ans[a[u]] += f[u];
    }
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
        if(l[a[i]]){
            Din[l[a[i]]] = 1;
            g[i].push_back(l[a[i]]);
        }
        l[a[i]] = i;
    }
    for(int i = n - 1; i >= 1; i--){
        if(Din[i] == 0){
            g[i + 1].push_back(i);
        }
    }
    dfs(n, 0);
#ifdef Ken
    for(int i = 1; i <= n; i++){
        cout << "f[" << i << "] = " << f[i] << '\n';
    }
#endif
    for(int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
    }
    puts("");
    return 0;
}