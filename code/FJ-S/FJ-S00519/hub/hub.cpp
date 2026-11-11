#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, T, n, k, ans;
vector<int>e[N];
int S[N], dep[N], fa[N], f[N];
void init(){
    ans = n;
    for(int i = 1;i <= n;++i)e[i].clear();
}
void dfs(int x){
    dep[x] = dep[fa[x]] + 1;
    for(int y : e[x]){
        if(fa[x] == y)continue;
        fa[y] = x; dfs(y);
    }
}
int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
int check(){
    int lca = n + 1, res = 0;
    for(int i = 1;i <= n;++i){
        f[i] = i;
        if(!S[i])continue;
        
        if(S[fa[i]])f[i] = find(fa[i]);
        for(int j = i + 1;j <= n;++j){
            if(!S[j])continue;
            int x = i, y = j, res = 0;
            while(x != y){
                if(dep[x] < dep[y])swap(x,y);
                x = fa[x];
                ++res;
            }
            lca = min(lca, res);
        }
    }
    for(int i = 1;i <= n;++i)if(S[i] && find(i) == i)++res;
    return res <= 2 ? lca : n + 1;
}
void dfs2(int x,int c){
    if(x > n){
        if(c==k)ans = min(ans, check());
        return;
    }
    dfs2(x + 1, c), S[x] = 1, dfs2(x + 1, c+1), S[x] = 0;
}
void solve(){
    scanf("%d%d", &n, &k);
    init();
    for(int i = 1;i < n;++i){
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].push_back(y), e[y].push_back(x);
    }
    if(k == 2){puts("1");return;}
    dfs(1);
    dfs2(1, 0);
    printf("%d\n", ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d", &c, &T);
    while(T--)solve();
    return 0;
}