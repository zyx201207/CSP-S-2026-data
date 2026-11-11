#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 5 * 1e5 + 610;
const int K = 5 * 1e5 + 100;
int c,n,m,d,q;
int w[N];
int dep[M],f[M][22],dis[M];
unordered_map<long long,long long>cnt;
struct node{
    int e;
    long long w;
};
vector<node>G[M];
int getid(int x,int op){
    if(op == 1){
        return cnt[x];
    }else if(op == 2){
        return K + x;
    }
    return K + x + 500;
}
void dfs(int u,int fa,long long w){
    dis[u] = dis[fa] + w;
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for(auto x : G[u]){
        int v = x.e;
        long long y = x.w;
        if(v == fa) continue;
        dfs(v,u,y);
    }
}
void init(){
    for(int j = 1;(1 << j) <= n;j++){
        for(int i = 1;i<=n;i++){
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
}
int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = 20;i>=0;i--){
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
    }
    if(u == v) return u;
    for(int i = 20;i>=0;i--){
        if(f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        int k,la = 0;
        cin>>k;
        for(int j = 1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            cnt[x]++;
            int a = getid(x,1),b = getid(la,1),c = getid(x,2);
            if(la != 0){
                G[a].push_back({b,0});
                G[b].push_back({a,0});
                cout<<a<<" "<<b<<'\n';
            }
            la = x;
            G[a].push_back({c,y});
            G[c].push_back({a,y});
            cout<<a<<" "<<c<<" "<<y<<'\n';
        }
    }
    for(int i = 1;i<=n;i++){
        int x = getid(i,2),y = getid(i,3);
        G[x].push_back({y,w[i]});
        G[y].push_back({x,w[i]});
        cout<<x<<" "<<y<<" "<<w[i]<<"!!!"<<'\n';
    }
    dfs(getid(1,3),0,0);
    init();
    while(q--){
        int u,v;
        cin>>u>>v;
        u = getid(u,3),v = getid(v,3);
        int lc = lca(u,v);
        cout<<lc<<'\n';
        cout<<dis[v] + dis[u] - 2 * dis[f[lc][0]]<<'\n';
    }
    return 0;
}