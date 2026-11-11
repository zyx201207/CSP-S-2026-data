#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500001],x2,y2,ans[100000];
struct Road{
    ll stopn;
    vector<pair<ll,ll>>stops;
}roads[501];
ll bfs(ll x,ll y);
int main() {
    freopen("./subway.in","r",stdin);
    freopen("./subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;
    for (ll i = 0;i < m;i++) {
        cin >> w[i];
    }
    for (ll i = 0;i < n;i++) {
        cin >> roads[i].stopn;
        for (ll j = 0;j < roads[i].stopn;j++) {
            ll tmp,tmp1;
            cin >> tmp >> tmp1;
            roads[i].stops.push_back({tmp,tmp1});
        }
    }
    for (ll i = 0;i < q;i++) {
        cin >> x2 >> y2;
        ans[i] = bfs(x2,y2);
    }
    for (ll i = 0;i < q;i++) {
        cout <<ans[i]<<endl;
    }
    return 0;
}
ll bfs(ll x,ll y) {
    ll result = 114514111;
    queue<pair<ll,ll>>qe;
    bool visited[m]={false};
    visited[x] = true;
    qe.push({x,0});
    while (!qe.empty()) {
        ll f =  qe.front().first;
        ll f1 = qe.front().second;
        qe.pop();
        if (f==y) {
            if (result == 114514111) {
                result = f1+w[y];
                continue;
            }
            result=min(result,f1+w[y]);
            continue;
        }
        for (ll i = 0;i < n;i++) {
            for (ll j = 0;j < roads[i].stopn;j++) {
                if (roads[i].stops[j].first==f) {
                    vector<pair<ll,ll>>this_road;
                    this_road = roads[i].stops;
                    for (ll k = 0;k < roads[i].stopn;k++) {
                        if (visited[this_road[k].first]!=true) {
                            qe.push({this_road[k].first,f1+this_road[j].second+this_road[k].second});
                            visited[this_road[k].first] = true;
                        }
                    }
                }
            }
        }
    }
    return result+w[x];
}
