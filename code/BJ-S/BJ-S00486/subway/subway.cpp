

#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e18;

struct Edge{
    long long to, weight;
};
struct Node{
    long long pos, far;

    bool operator < (const Node &X) const {
        return X.far < far;
    }
};

int c,m,n,d,q;
long long w[500009];
vector<Edge> v[509];
vector<Edge> f[500009];
long long dis[509][509];
int vis[509][509];

void Dijkstra(int s) {
    priority_queue<Node> pq;
    Node solo;

    dis[s][s] = 0;
    solo.far = 0, solo.pos = s;
    pq.push(solo);

    while(!pq.empty()) {
        solo = pq.top();
        pq.pop();

        if(vis[s][solo.pos]) {
            continue;
        }

        vis[s][solo.pos] = 1;

        for(int i = 0; i < v[solo.pos].size(); i++) {
            Edge cur = v[solo.pos][i];

            if(dis[s][cur.to] > dis[s][solo.pos] + cur.weight) {
                Node curNode;

                dis[s][cur.to] = dis[s][solo.pos] + cur.weight;
                curNode.far = dis[s][cur.to];
                curNode.pos = cur.to;
                pq.push(curNode);
            }
        }
     }
}

int main () {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        for(int j = 1; j <= k; j++) {
            Edge solo;
            int x;
            cin >> x >> solo.weight;
            solo.to = i;
            f[x].push_back(solo);
         }
    }


    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < f[i].size(); j++) {
            int starti = f[i][j].to;

            for(int k = j + 1; k < f[i].size(); k++) {
                int endi = f[i][k].to;
                Edge solo;

                solo.weight = f[i][j].weight + f[i][k].weight;
                solo.to = endi;
                v[starti].push_back(solo);
                solo.to = starti;
                v[endi].push_back(solo);
            }
        }
    }


    memset(dis, 0x3f, sizeof(dis));

    for(int i = 1; i <= n; i++) {
        Dijkstra(i);
    }

    while(q--) {
        int x,y;
        long long ans = 0, res = MAXN;
        cin >> x >> y;
        ans = w[x] + w[y];

        for(int i = 0; i < f[x].size(); i++) {
            Edge solo = f[x][i];

            for(int j = 0; j < f[y].size(); j++) {
                Edge cur = f[y][j];

                res = min(ans + dis[solo.to][cur.to] + (solo.weight + cur.weight) , res);
            }
        }

        cout << res << endl;
    }

    return 0;
}
