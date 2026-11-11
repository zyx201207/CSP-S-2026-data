#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool st;
const int N = 1000;
const ll inf = 1e18;
int id, n, k, ans = 1e9;
vector<int> g[N];
bool ed;
double Time(){
    return (double)clock()/CLOCKS_PER_SEC;
}
int dis[N][N];
void dfs(int p, int fa, int now){
    for(int x:g[p]){
        if(x==fa) continue;
        dis[now][x] = dis[now][p] + 1;
        dfs(x,p,now);
    }
}
int f[N]; bool vis[N];
void dfs2(int p, int fa){
    f[p] = 1;
    for(int x:g[p]){
        if(x==fa) continue;
        if(!vis[x]) continue;
        dfs2(x,p);
    }
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int t; cin >> id >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1,x,y; i<n; ++i){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1; i<=n; ++i){
            dfs(i,0,i);
        }
        for(ll s=0; s<(1<<n); ++s){
            if(__builtin_popcount(s)^k) continue;
            for(int i=1; i<=n; ++i){
                vis[i] = bool( s & (1<<i-1) );
                f[i] = 0;
            }
            int cnt = 0;
            for(int i=1; i<=n; ++i){
                if(!vis[i]) continue;
                if(vis[i] && f[i]) continue;
                ++cnt; dfs2(i,0);
            }
            if(cnt>2) continue;
            int res = 0;
            for(int i=1; i<=n; ++i){
                if(vis[i]) continue;
                int rr = 1e9;
                for(int j=1; j<=n; ++j){
                    if(!vis[j]) continue;
                    rr = min(rr, dis[i][j]);
                }
                res = max(res, rr);
            }
            ans = min(ans, res);
        }
        cout << ans << endl;
        ans = 1e9;
        for(int i=1; i<=n; ++i) g[i].clear();
    }

    // cerr<<Time()<<'s'<<endl;
    // cerr<<(&ed-&st)/1024.0/1024<<endl;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/