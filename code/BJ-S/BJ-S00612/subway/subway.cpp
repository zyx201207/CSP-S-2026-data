#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n, m, d, q;
struct station {
    ll place;
    ll time;
    ll way;
};
station a[500005];
vector<ll> p[500005];
ll need_time[500005];
ll dfs(ll from, ll to) {
    queue<ll> q;
    queue<ll> cost;
    queue<ll> wayy;
    q.push(from);
    cost.push(need_time[from] + a[from].time);
    wayy.push(a[from].way);
    ll minn = 10000000000;
    while(!q.empty()) {
        ll now = q.front();
        ll costt = cost.front();
        ll now_way = wayy.front();
        q.pop();
        cost.pop();
        wayy.pop();
        if(now == to) {
            minn = min(minn, costt);
            minn += a[to].time + need_time[to];
            return minn;
        }
        if(costt > minn) {
            continue;
        }
        //cout << p[now].size() << endl;
        for(ll i = 0;i < p[now].size();i++) {
            q.push(p[now][i]);
            //cout << "p[now][i] = " << p[now][i] << endl;
            if(now_way != a[p[now][i]].way) {
                cost.push(costt + a[p[now][i]].time + a[now].time);
                wayy.push(a[p[now][i]].way);
                continue;
            }
            cost.push(costt);
            wayy.push(now_way);
        }
    }
    return minn;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(ll i = 1;i <= m;i++) {
        cin >> need_time[i];
    }
    for(ll i = 1;i <= n;i++) {
        ll k;
        cin >> k;
        for(ll j = 1;j <= k;j++) {
            station x;
            cin >> x.place >> x.time;
            x.way = i;
            a[j] = x;
            if(j > 1) {
                p[a[j - 1].place].push_back(x.place);
                p[x.place].push_back(a[j - 1].place);
                cout << a[j - 1].place << " " << x.place << endl;
            }
        }
    }
    for(int i = 1;i <= q;i++) {
        ll x, y;
        cin >> x >> y;
        cout << dfs(x, y) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
