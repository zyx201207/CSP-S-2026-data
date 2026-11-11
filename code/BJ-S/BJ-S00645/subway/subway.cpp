#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXM=5e5+5;
ll w[MAXM];
ll k[505];
struct node{
    ll b, c;
};
map<ll, ll> mp;
vector<pair<ll, ll>> g[MAXM];
vector<node> G[MAXM];
// ll d[MAXM][505];
ll x[MAXM], y[MAXM];
ll dis[505];
void dijkstra(ll st){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({0, st});
    dis[st]=0;
    while(!pq.empty()){
        pair<ll, ll> now=pq.top();
        pq.pop();
        for(auto k:G[now.second]){
            if(now.first+k.c<dis[k.b]){
                dis[k.b]=now.first+k.c;
                pq.push({dis[k.b], k.b});
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ll c, n, m, d1, q;
    cin >> c >>  n >> m >> d1 >> q;
    for(ll i=1;i<=m;i++){
        cin >> w[i];
    }
    for(ll i=1;i<=n;i++){
        cin >> k[i];
        for(ll j=1;j<=k[i];j++){
            ll a, t;
            cin >> a;
            cin >> t;
            mp[a*500005+i]=t;
            g[a].push_back({i, t});
        }
    }
    for(ll i=1;i<=m;i++){
        for(auto k:g[i]){
            for(auto k1:g[i]){
                if(k.first==k1.first) continue;
                G[k.first].push_back({k1.first, k.second+k1.second});
            }
        }
    }
    for(ll i=1;i<=q;i++){
        cin >> x[i] >> y[i];
        ll ans=w[x[i]]+w[y[i]];
        ll minn1=1e18;
        for(auto k:g[x[i]]){
            memset(dis, 0x3f, sizeof(dis));
            ll sum=mp[x[i]*500005+k.first];
            dijkstra(k.first);
            ll minn=1e18;
            for(auto k1:g[y[i]]){
                minn=min(dis[k1.first]+mp[y[i]*500005+k1.first], minn);
            }
            minn1=min(minn1, sum+minn);
        }
        cout << ans+minn1 << endl;
    }
}