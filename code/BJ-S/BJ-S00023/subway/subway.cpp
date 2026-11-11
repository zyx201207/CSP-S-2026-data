#include <bits/stdc++.h>
#define pii pair<long long,int>
using namespace std;
const int N = 5e5 + 10;
int c,n,m,d,q;
vector<pii > e[1005],h[1005];
vector<pii > g[N];
long long w[N],dis[510][510];
bool vis[N];

void dij(int s) {
    priority_queue<pii,vector<pii >,greater<pii > > p;
    p.push({0ll,s});
    for(int i = 0;i < 505;i ++) dis[s][i] = (long long)(1e18);
    memset(vis,0,sizeof vis);
    dis[s][s] = 0ll;
    while(p.size()) {
        int u = p.top().second;
        p.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto ed : h[u]) {
            int v = ed.second;
            long long w = ed.first;
            if(dis[s][v] > dis[s][u] + w) {
                dis[s][v] = dis[s][u] + w;
                p.push({dis[s][v],v});
            }
        }
    }
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;i ++) {
        cin >> w[i];
    }

    for(int i = 1;i <= n;i ++) {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++) {
            int a,t;
            cin >> a >> t;
            e[i].push_back({t,a});
            g[a].push_back({t,i});
        }
    }

    for(int i = 1;i <= n;i ++) {
        for(pii j : e[i]) {
            int w1 = j.first;
            int u = j.second;
            for(pii k : g[u]) {

                int w2 = k.first;
                int v = k.second;
                if(i == v) continue;
                h[i].push_back({w1+w2,v});
            }
        }
    }

    for(int i = 1;i <= n;i ++) {
        dij(i);
    }

    for(int i = 1;i <= q;i ++) {
        int x,y;
        cin >> x >> y;
        long long ans = (long long)(1e18);
        for(pii j : g[x]) {
            int u = j.second;
            int w1 = j.first;
            for(pii k : g[y]) {
                int v = k.second;
                int w2 = k.first;
                ans = min(ans,dis[u][v] + w1 + w2 + w[x] + w[y]);
            }
        }
        cout <<ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

