#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
struct dist{
    int node; int d;
    dist(){};
    dist(int p1, int p2){
        node = p1; d = p2;
    };
    bool operator<(const dist& other) const{return d < other.d;}
    bool operator>(const dist& other) const{return d > other.d;}
};
vector<dist> G[505005];
int w[500005]; bool vis[505005];

void add_edge(int u, int v, int wi){
    G[u].push_back(dist(v, wi));
}

vector<int> dijkstra(int s, int e){
    vector<int> dis(n+m+1, LONG_LONG_MAX - 1000);
    priority_queue<dist, vector<dist>, greater<dist> > q;
    for(int i=0;i<=n+m;i++){
        vis[i] = 0;
    }
    dis[s] = 0;
    q.push(dist(s, dis[s]));
    while(!q.empty()){
        dist u = q.top(); q.pop();
        vis[u.node] = 1;
        for(auto i : G[u.node]){
            int ev = i.node; int ew = i.d;
            if(vis[ev]) continue;
            if(dis[ev] > dis[u.node] + ew){
                dis[ev] = dis[u.node] + ew;
                q.push(dist(ev, dis[ev]));
            }

        }
    }
    for(int i=n+1;i<=n+m;i++){
        dis[i] += w[s-n];
        dis[i] += w[i-n];
    }
    return dis;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }

    for(int i=1;i<=n;i++){
        int k; cin >> k;
        vector<int> dat; int s=0;
        for(int i=0;i<2*k;i++){
            int tmp; cin >> tmp; dat.push_back(tmp);
        }
        for(int j=0;j<dat.size();j+=2){
            add_edge(dat[j] + n, i, dat[j+1]);
            add_edge(i, dat[j] + n, dat[j+1]);
        }
    }
    vector<vector<int> > dmx; int cnt=0;
    vector<pair<int, int> > query; vector<int> qq; vector<int> pp(m+1, 0);
    for(int i=0;i<q;i++){
        int s, e; cin >> s >> e;
        query.push_back(make_pair(s, e));
        if(pp[s] == 0){
            pp[s] = 1; qq.push_back(s);
        }
    }
    for(auto s : qq){
        dmx.push_back(dijkstra(s+n, s+n));
        pp[s] = cnt++;
    }
    for(auto qy : query){
        cout << dmx[pp[qy.first]][qy.second + n] << endl;
    }




    return 0;

}
