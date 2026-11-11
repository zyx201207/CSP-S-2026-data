#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9*1ll;
constexpr int K = 5e5+5;
constexpr int M = 2e4+5;
int c, n, m, d, q;
int temp1[K], temp2[K];
struct Node{
    int v, w;
};
struct Edge{
    int u, v, w;
    friend bool operator<(Edge x, Edge y){
        return x.w>y.w;
    }
};
vector<Node> a[M];
int dist[M];
int w[M];
int mindist(int x, int y){
    for(int i=1;i<=m;i++) dist[i] = INF;
    dist[x] = 0;
    priority_queue<Edge, vector<Edge>> pq;
    for(auto iter = a[x].begin();iter != a[x].end();iter++){
        pq.push({x, (*iter).v, (*iter).w});
    }
    while(!pq.empty()){
        Edge f = pq.top();
        pq.pop();
        if(dist[f.u]+f.w>dist[f.v]) continue;
        for(auto iter = a[f.v].begin();iter != a[f.v].end();iter++){
            int v = (*iter).v, w = (*iter).w;
            pq.push({f.v, v, w});
        }
        dist[f.v] = dist[f.u]+f.w;
    }
    return dist[y];
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1, k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++) cin>>temp1[j]>>temp2[j];
        if(k>=2){
            a[temp1[1]].push_back({temp1[2], temp2[1]+temp2[2]});
            for(int j=3;j<=k;j++) a[temp1[j-1]].push_back({temp1[j], temp2[j]-temp2[j-1]});
            a[temp1[k]].push_back({temp1[k-1], temp2[k]+temp2[k-1]});
            for(int j=k-1;j>=2;j--) a[temp1[j]].push_back({temp1[j-1], temp2[j-1]-temp2[j]});
        }
    }
    /*
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<((a[i][j]==INF)?char('X'): a[i][j])<<" \n"[j==m];
        }
    }
    */
    /*
    int mina = -INF;
    for(int i=1;i<=m;i++){
        for(auto iter = a[i].begin();iter != a[i].end();iter++){
            mina = min(mina, (*iter).w);
        }
    }
    if(mina>=0) mina=0;
    for(int i=1;i<=m;i++){
        for(auto iter=a[i].begin();iter != a[i].end();iter++){
            (*iter).w += -mina;
        }
    }
    */
    /*
    for(int i=1;i<=m;i++){
        for(auto iter=a[i].begin();iter != a[i].end();iter++){
            cout<<(*iter).v<<' '<<(*iter).w<<' ';
        }
        cout<<'\n';
    }
    */
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<mindist(x, y)<<'\n';
    }
    return 0;
}
//Why this code Re?!!
/*
I am a 9 grade student, that will AFO after the competition.But I just got 100+0+0+0, I want to use the dijistra to get 60pts at T2, but there are many BUGS!!I cant fix these at all.
I will get the 2=, or lower.

Just these.
*/




