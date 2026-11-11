#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5 + 10;
ll c, t;
ll a[maxn];
ll vis[maxn];
queue<pair<ll, ll>> q1;
struct node{
    ll v, w;
}G[maxn];
void dij(ll s),ll n{
    priority_queue<pair<ll, ll>> q;
    for(int i = 1; i <= n; i ++){
        done[i] = 0;
        dist[i] = 1e18;
    }
    q.push({0, s});
    done[s] = 1;
    dist[s] = 0;
    while(!q.empty()){
        ll u = q.top().second();
        if(done[u]) continue;
        done[u] = 1;
        for(auto x:G[u]){
            ll v = x.v;
            ll w = x.w;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
            if(dist[u] + w == dist[v]){
                q1.push({u, v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r", stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    while(t --){
        ll n, d;
        cin >>n >> d;
        ll a[maxn] = {};
        G[maxn].clear();
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(j != i &&abs(a[i] - a[j]) <= d)){
                    G[i].push_back({j, abs(a[i] - a[j])});
                    G[j].push_back({i, abs(a[i] - a[j])});
                }
            }
        }
        dij(a[1], n);
        cout << q1.size() << endl;
        while(!q1.empty()){
            q1.pop()
        };
    }
    return 0;
}
