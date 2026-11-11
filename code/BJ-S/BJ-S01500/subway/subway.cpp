#include<bits/stdc++.h>
using namespace std;

long long c, n, m, d, T, dis[510], w[500100], se[510][510]; /// !!!!!! shu ju fan wei

struct node{
    long long x, val;
    bool operator >(node p) const{
        return val > p.val;
    }
};

priority_queue<node, vector<node>, greater<node> >q;

vector<node>g[510];
vector<node>pg[500100];

void bfs(int st, int en){
    long long minn = 0x3f3f3f3f3f3f3f3f;
    if(st == en){
        cout<<0<<endl;
        return;
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < pg[st].size(); i++){
        int u = pg[st][i].x;
        q.push({u, pg[st][i].val});
        dis[u] = pg[st][i].val;
    }
    while(!q.empty()){
        node t = q.top();
        int u = t.x;
        q.pop();
        if(dis[u] < t.val){
            continue;
        }
        for(int i = 0; i < g[u].size(); i++){
            node p = g[u][i];
            int v = p.x, val = p.val;
            if(dis[u]+val < dis[v]){
                dis[v] = dis[u]+val;
                q.push({v, dis[v]});
            }
        }
    }
    for(int i = 0; i < pg[en].size(); i++){
        int v = pg[en][i].x, val = pg[en][i].val;
        minn = min(minn, dis[v]+val);
    }
    cout<<minn+w[st]+w[en]<<endl;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>T;
    for(int i = 1; i <= m; i++){
        cin>>w[i];
    }
    for(int i = 1 ; i <= n; i++){
        int k;
        int u = i;
        cin>>k;
        for(int j = 1; j <= k; j++){
            int v, val;
            cin>>v>>val;
            pg[v].push_back({u, val});
        }
    }
    memset(se, 0x3f, sizeof(se));
    for(int v = 1; v <= m; v++){
        for(int i = 0; i < pg[v].size(); i++){
            for(int j = i+1; j < pg[v].size(); j++){
                int l = pg[v][i].x, r = pg[v][j].x;
                se[l][r] = min(se[l][r], pg[v][i].val+pg[v][j].val);
                se[r][l] = min(se[r][l], pg[v][i].val+pg[v][j].val);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            if(se[i][j] < 1e12){
                g[i].push_back({j, se[i][j]});
            }
        }
    }
    while(T--){
        int ta, tb;
        cin>>ta>>tb;
        bfs(ta, tb);
    }
    return 0;
}