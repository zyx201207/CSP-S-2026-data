#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
const ll N=505;
const ll M=500005;
struct gnode {
    ll v,w;
    friend bool operator>(const gnode &a, const gnode &b) {
        return a.w > b.w;
    }
};
ll *dijkstra(vector<gnode> g[], ll n, ll start, ll dist[]) {
    priority_queue<gnode, vector<gnode>, greater<gnode> > q;
    memset(dist, 0x3f, sizeof(ll) * (n + 1));
    dist[start] = 0;
    q.push((gnode){start, 0});
    while(!(q.empty())){
        const gnode &u=q.top();
        q.pop();
        for(const gnode &v : g[u.v]){
            if(dist[v.v] > dist[u.v] + v.w){
                dist[v.v] = dist[u.v] + v.w;
                q.push((gnode){v.v, dist[v.v]});
            }
        }
    }
    return dist;
}
vector<gnode> g[N*3];
ll c,n,m,d,q,w[M],a,t,k[M],start,end_,dist[M];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(ll i=1;i<=m;i++){
        cin >> w[i];
        g[i + 1].push_back((gnode){i + 2, w[i]});
        g[i + 2].push_back((gnode){i + 1, w[i]});
    }
    for(ll i=1;i<=n;i++){
        cin >> k[i];
        for(ll j=1;j<=k[i];j++){
            cin >> a >> t;
            g[a].push_back((gnode){a + 1, t});
            g[a + 1].push_back((gnode){a, t});
        }
    }
    for(ll i=1;i<=q;i++){
        cin >> start >> end_;
        cout << dijkstra(g, n, start, dist)[end_] << "\n";
    }
    return 0;
}
