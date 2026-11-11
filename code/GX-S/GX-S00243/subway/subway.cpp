#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10,MAXM = 8e5 + 10,MAXQ = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int head[MAXN];
int to[MAXM << 1];
int nxt[MAXM << 1];
int val[MAXM << 1];
int roadId[MAXM << 1];
int cntg;

int hallVal[MAXN][21];
int dist1[MAXN],dist2[MAXN];
int vis1[MAXN],vis2[MAXN];
int s,t;
int weight[MAXN];
int ans[MAXQ];
int c,n,m,d,q,k;

struct Node{
    int id;
    int type;
    int dis;
    int road;

    bool operator(const Node& other) const{
        return dis > other.dis;
    }
};
priority_queue<Node>q;

void addEdge(int u,int v,int id){
    nxt[++cntg] = head[u];
    head[u] = cntg;
    to[cntg] = v;
    roadId[cntg] = id;
}

bool check(int type,int id){
    if(type == 2){
        return vis2[id];
    }else{
        return vis1[id];
    }
}

void getsign(int type,int id){
    if(type == 2){
        vis2[id] = true;
    }else{
        vis1[id] = true;
    }
}

void build(){
    for(int i = 1;i<=m;i++){
        dist1[i] = INF;
        dist2[i] = INF;
        vis1[i] = false;
        vis2[i] = false;
    }
}

void dijkstra(){
    dist2[s] = weight[s];
    vis2[s] = true;
    q.push({s,2,dist2[s],0});
    while(!q.empty()){
        Node u = q.top();
        q.pop();
        int id = u.id;
        int type = u.type;
        int dis = u.dis;
        int road = u.road;
        if(check(type,id)){
            continue;
        }
        getsign(type,id);
        if(type == 2){
            for(int i = 1;i<=d;i++){
                if(hallVal[id][i] == 0) continue;
                if(dis + hallVal[id][i] < dist1[id] && !vis1[id]){
                    dist1[id] = dis + hallVal[id][i];
                    q.push({id,1,dist1[id],i});
                }
            }
        }else{
            for(int ei = head[u],v;ei != 0;ei = nxt[ei]){
                if(roadId[ei] != road) continue;
                v = to[ei];
                if(dis < dist1[v] && !vis1[v]){
                    dist1[v] = dis;
                    q.push({v,1,dis,road});
                }
            }
            if(dis + hallVal[id][road] < dist2[id] && !vis2[id]){
                dist2[id] = dis + hallVal[id][road];
                q.push({id,2,dist2[id],0});
            }
        }
    }
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++){
        cin >> weight[i];
    }
    for(int i = 1;i<=n;i++){
        cin >> k;
        for(int j = 1,u,v,w;j<=k;j++){
            cin >> v;
            cin >> w;
            hallVal[v][i] = w;
            if(j != 1){
                addEdge(u,v,i);
                addEdge(v,u,i);
            }
            u = v;
        }
    }
    for(int i = 1;i<=q;i++){
        cin >> s >> t;
        build();
        dijkstra();
        ans[i] = dist2[t] + weight[t];
    }
    for(int i = 1;i<=q;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
