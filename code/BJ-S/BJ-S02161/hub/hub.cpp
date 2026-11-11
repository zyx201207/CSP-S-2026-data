#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, m, ans = 0;
vector<ll>a, sz, dis;
vector<vector<ll>> g;
void dfs(ll u, ll fa){
    for(ll& v:g[u]){
        if(v==fa) continue;
        dis[v] = dis[u]+1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ll c, t;cin>>c>>t;
    while(t--){
        ll n, k;cin>>n>>k;
        a.assign(n+1, 0);
        sz.assign(n+1, 1);
        dis.assign(n+1, 0);
        g.assign(n+1, vector<ll>());
        for(int i = 1, u, v;i<=n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }cout<<rand()%(n-1)<<endl;
    }
}/*
0pts
*/