#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll w, id;
};
ll c, n, m, d, q;
ll w[500010];
ll vis[500010];
int dis[500010], dd[500010];
vector<pair<ll,ll>> a[500010];
ll dijsktra(ll x, ll y){
    priority_queue<node> q;
    q.push({0, x});
    vis[x] = 1;
    for(int i = 1; i <= n; i++) dd[i] = 1e18;
    dis[x] = 0;
    while(q.size()){
        int x = q.top().id;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(auto i : a[x]){
            if(i.second+dis[i.first] >= dd[i.first]){
                dd[i.first] = i.second+dd[x];
                q.push({dd[i.first], i.first});
            }
        }
    }
    return dd[y];
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int A, t;
            cin >> A >> t;
            int k6 = 1e6;
            a[A].push_back({j + k6, t});
            a[j + k6].push_back({A, t});
        }
    }
    while(q--){
        ll x, y;
        cin >> x >> y;
        cout << dijsktra(x,y) + w[x] + w[y] << "\n";
    }
    return 0;
}
