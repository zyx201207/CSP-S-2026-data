#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct node{
    ll v, w, lst;
    bool operator<(node o) const{
        return w>o.w;
    }
};
ll c, n, m, d, q, cnt = 0;
vector<ll> dis, vis, w, lsts;
vector<vector<node>> g;
vector<vector<ll>> has, tim;
void dij(ll s){
    dis[s] = 0;
    priority_queue<node> pq;
    pq.push(node{s, 0, 0});
    while(!pq.empty()){
        ll u = pq.top().v;
        ll lst = pq.top().lst;
        pq.pop();
        //cout<<u<<endl;
        if(vis[u]) continue;
        vis[u] = 1;
        for(node& v:g[u]){
            ll z = 0;
            if(u<m&&lst!=-1&&lst!=v.v){
                //cout<<"IN"<<' '<<lst<<' '<<u<<' '<<v.v-m<<endl;
                z = tim[lst][u]+tim[v.v-m][u];
                //cout<<u<<' '<<v.v<<' '<<tim[lst][u]<<' '<<tim[v.v-m][u]<<endl;
                //cout<<111<<endl;
            }
            if(dis[v.v]>=dis[u]+v.w+z){
                //cout<<111<<endl;
                dis[v.v] = dis[u]+v.w+z;
                if(v.v<=m)lsts[v.v] = lst;
                pq.push(node{v.v, dis[v.v], (v.v>m?v.v-m:lst)});
            }
        }//cout<<"FINE"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    g.assign(m+1, vector<node>());cnt = m;
    has.assign(m+1, vector<ll>());
    tim.assign(n+1, vector<ll>(m+1, 0));
    w.assign(m+1, 0);
    for(int i = 1;i<=m;i++)cin>>w[i];
    for(int i = 1;i<=n;i++){
        ll k;cin>>k;
        ll root = ++cnt;
        g.push_back(vector<node>());
        for(int j = 1;j<=k;j++){
            ll a, t;cin>>a>>t;
            has[a].push_back(root);
            tim[i][a] = t;
            g[a].push_back({root, 0, 0});
            g[root].push_back({a, 0, 0});
        }
    }
    while(q--){
        dis.assign(g.size()+1, 1e18);
        vis.assign(g.size()+1, 0);
        lsts.assign(m+1, 0);
        ll l, r;cin>>l>>r;
        dij(l);
        cout<<dis[r]+w[l]+w[r]+tim[lsts[r]][r]<<endl;
    }
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
100pts
*/