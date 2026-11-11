#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    int idx,l,r;
} ask[100005];

int c,n,m,d,q,w[125255],tot;
bool flag[125255];
ll dist[125255],out[100005];

vector <pair <ll,int>> v[125255];

bool cmp(node a,node b) {
    return a.l < b.l;
}

void dijkstra(int root) {
    priority_queue <pair <ll,int>,vector <pair <ll,int>>,greater <pair <ll,int>>> q;
    memset(dist,0x3f3f3f3f,sizeof(dist));
    memset(flag,false,sizeof(flag));
    q.push({0,root});
    dist[root] = 0;
    while (!q.empty()) {
        int w = q.top().first,u = q.top().second;
        q.pop();
        if (flag[u]) continue;
        flag[u] = true;
        for (int i = 0; i < v[u].size(); i++) {
            ll tmpw = v[u][i].first;
            int tmpu = v[u][i].second;
            if (dist[u] + tmpw < dist[tmpu]) {
                dist[tmpu] = dist[u] + tmpw;
                q.push({dist[tmpu],tmpu});
            }
        }
    }
    return ;
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        int num[125255],now[125255];
        for (int j = 1; j <= len; j++)
            cin >> now[j] >> num[j];
        for (int j = 1; j <= len; j++) {
            for (int k = j + 1; k <= len; k++) {
                v[now[j]].push_back({(ll) num[j] + num[k],now[k]});
                v[now[k]].push_back({(ll) num[j] + num[k],now[j]});
            }
        }
    }
/*    cout <<endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j].second << " " << v[i][j].first << " ";
        cout << endl;
    }*/
    while (q--) {
        tot++;
        cin >> ask[tot].l >> ask[tot].r;
        ask[tot].idx = tot;
    }
    sort(ask + 1,ask + tot + 1,cmp);
    int lst = 0;
    for (int i = 1; i <= tot; i++) {
        if (lst != ask[i].l) {
            lst = ask[i].l;
            dijkstra(ask[i].l);
        }
        out[ask[i].idx] = dist[ask[i].r] + w[ask[i].l] + w[ask[i].r];
    }
    for (int i = 1; i <= tot; i++)
        cout << out[i] << endl;
    return 0;
}
