#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int v;
    ll w;
};
int c,n,m,d,q;
int w[505];
int k[505];
int di[505];
bool vis[505];
int a[505][500005];
int t[505][500005];
vector<node> adj[100005];
bool operator < (node x,node y){
    return x.w > y.w;
}
void dij(int s){
    memset(di,0x3f,sizeof(di));
    memset(vis,0,sizeof(vis));
    di[s] = 0;
    priority_queue<node> q;
    q.push({s,0});
    while(q.size()){
        node cur = q.top();
        q.pop();
        int u = cur.v;
        if(vis[u]){
            continue;
        }
        vis[u] = 1;
        for(auto x:adj[u]){
            int v = x.v;
            ll w = x.w;
            if(di[u]+w < di[v]){
                di[v] = di[u]+w;
                q.push({v,di[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q ;
    for(int i = 1; i <= m; i++){
        cin >> w[i] ;
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i] ;
        for(int j = 1; j <= k[i]; j++){
            cin >> a[i][j] >> t[i][j] ;
        }
        for(int j = 1; j <= k[i]; j++){
            for(int l = j+1; l <= k[i]; l++){
                adj[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
                adj[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
            }
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y ;
        dij(x);
        cout << di[y]+w[x]+w[y] << "\n" ;
    }
    return 0;
}
