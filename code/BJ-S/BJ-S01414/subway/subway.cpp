#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 5e5 + 10;
const int N = 5e2 + 10;
struct node { ll v,w; };
ll w[M]; vector<node> a[M];
ll dis[505][505];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q; cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) {
        ll x; cin >> x;
        for(int j = 1;j <= x;j++) {
            ll cur,qwq; cin >> cur >> qwq;
            a[cur].push_back({i,qwq});
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            dis[i][j] = 1e18;
        }
    }
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 0;j < a[i].size();j++) {
            node Cjq1 = a[i][j];
            for(int k = 0;k < a[i].size();k++) {
                if(j == k) continue;
                node Cjq2 = a[i][k];
                dis[Cjq1.v][Cjq2.v] = min(dis[Cjq1.v][Cjq2.v],Cjq1.w + Cjq2.w);
            }
        }
    }
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        int x,y; cin >> x >> y;
        ll ans = 1e18;
        for(int i = 0;i < a[x].size();i++) {
            for(int j = 0;j < a[y].size();j++) {
                node Cjq1 = a[x][i],Cjq2 = a[y][j];
                ans = min(ans,dis[Cjq1.v][Cjq2.v] + Cjq1.w + Cjq2.w);
            }
        }
        cout << w[x] + w[y] + ans << "\n";
    }
    return 0;
}
