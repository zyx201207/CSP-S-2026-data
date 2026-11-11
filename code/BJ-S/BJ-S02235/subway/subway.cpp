#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e4+5;
ll n, m, d, qs, a[N], b[2][N];
bool vis[2][N];
struct dat{
    ll c, v, t;
    bool operator <(const dat x)const{
        return t>x.t;
    }
};
vector<dat> g[2][N];
priority_queue<dat> q;

ll bfs(int s, int e){
    memset(b, 0x3f, sizeof b);
    b[0][s]=0; vis[0][s]=1;
    q.push({0, s, 0});
    while(!q.empty()){
        dat u=q.top(); q.pop();
        vis[u.c][u.v]=0;
        for(auto v:g[u.c][u.v])
            if(b[v.c][v.v]>b[u.c][u.v]+v.t){
                b[v.c][v.v]=b[u.c][u.v]+v.t;
                if(!vis[v.c][v.v]){
                    vis[v.c][v.v]=1;
                    q.push({v.c, v.v, b[v.c][v.v]});
                }
            }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &m, &m, &n, &d, &qs);
    for(int i=1;i<=n;i++)
        scanf("%lld", &a[i]);
    for(int i=1,k;i<=m;i++){
        scanf("%lld", &k);
        for(int j=1,u,v;j<=k;j++){
            scanf("%lld%lld", &u, &v);
            g[0][u].push_back({1, i, v});
            g[1][i].push_back({0, u, v});
        }
    }
    int u, v;
    while(qs--){
        scanf("%lld%lld", &u, &v);
        bfs(u, v);
        printf("%lld\n", a[u]+a[v]+b[0][v]);
    }
    return 0;
}