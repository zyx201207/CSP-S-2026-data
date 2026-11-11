#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int C, N, M, D, Q;

vector<vector<pair<int, int>>> g;

long long dijkstra(int x, int y) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, x));
    vector<ll> dist(N+M, 1e18);
    dist[x] = 0;
    vector<bool> vst(N+M, false);

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vst[u]) continue;
        vst[u] = true;
        for(pair<int, int> p : g[u]) {
            int w = p.first;
            int v = p.second;
            if(vst[v]) continue;
            if(dist[u]+w<dist[v]) {
                dist[v] = dist[u]+w;
                pq.push(make_pair(dist[u]+w, v));
            }
        }
    }
    return dist[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin>>C>>N>>M>>D>>Q;
    g = vector<vector<pair<int, int>>>(N+M); // last M is stations, before is railways
    vector<int> w(M); // 0-base
    for(int i=0;i<M;i++) {
        cin>>w[i];
    }
    for(int i=0;i<N;i++) {
        int K;
        cin>>K;
        for(int j=0;j<K;j++) {
            int a, t;
            cin>>a>>t;
            a--;
            //cout<<N+a<<" "<<i<<" "<<t<<endl;
            g[i].push_back(make_pair(t, N+a)); // value, to
            g[N+a].push_back(make_pair(t, i));
        }
    }
    for(int i=0;i<Q;i++) {
        int x, y;
        cin>>x>>y;
        x--; y--;
        //cout<<w[x]<<" "<<w[y]<<endl;
        cout<<dijkstra(N+x, N+y)+w[x]+w[y]<<'\n';
    }
    return 0;
}