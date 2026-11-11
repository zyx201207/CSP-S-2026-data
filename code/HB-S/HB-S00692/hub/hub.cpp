#include <bits/stdc++.h>
using namespace std;

inline int read(){
    int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
inline void print(int x){
    if(x < 0) {x = -x; putchar('-');}
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
const int N = 105;
int C,T,n,K,cnt;
vector<int> e[N];
bool vis[N];
int flo[N][N],fl[N][N];
void dfs(int u,int mask){
    if(vis[u]) return;
    if(!(mask&(1<<(u-1)))) return;
    vis[u] = true;
    for(int v,i = 0;i< e[u].size();i++){
        v = e[u][i];
        if(!vis[v] && (mask&(1<<(v-1)))) dfs(v,mask);
    }
        
}
void solve(){
    n = read(); K = read(); 
    for(int i = 1;i <= n;i++){
        e[i].clear();
        vis[i] = false;
        for(int j = 1;j <= n;j++) flo[i][j] = 1e9;
        flo[i][i] = 0;
    }
    for(int u,v,i = 1;i < n;i++){
        u = read(); v = read();
        flo[u][v] = flo[v][u] = 1;
    }
    for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)for(int k = 1;k <= n;k++){
        if(i == j || j == k || i == k) continue;
        flo[i][j] = min(flo[i][j],flo[i][k] + flo[k][j]);
    }
    // cout << calc(1,4) << '\n';
    // cout << n << '\n';
    int res = 1e9;
    for(int mask = 1;mask < (1 << n);mask++){
        for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++) fl[i][j] = flo[i][j];
        cnt = 0;
        // printf("now mask = %d\n",mask);
        int num = __builtin_popcount(mask);
        if(num != K) continue;
        for(int i = 1;i <= n;i++) vis[i] = false;
        for(int i = 1;i <= n;i++)if((mask & (1 << (i - 1))) && !vis[i]){
            cnt++;
            dfs(i,mask);
        }
        if(cnt > 2) continue;
        for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)if((mask&(1<<(i-1))) && (mask&(1<<(j-1)))){
            fl[i][j] = 0;
        }
        for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)for(int k = 1;k <= n;k++){
            if(i == j || j == k || i == k) continue;
            fl[i][j] = min(fl[i][j],fl[i][k] + fl[k][j]);
        }
        int dis,ans = -1;
        for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)if((mask&(1<<(j-1))) && i != j){
            // puts("666");
            dis = fl[i][j];
            ans = max(dis,ans);
        }
        printf("now mask = %d ans = %d\n",mask,ans);
        res = min(res,ans);
    }
    print(res); puts("");
}
int main(){ 
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    C = read(); T = read();
    while(T--) solve();
    return 0;
}