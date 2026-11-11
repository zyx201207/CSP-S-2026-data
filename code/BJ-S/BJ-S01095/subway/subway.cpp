#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 509,M=5e5+9,D=1e6+9;

int c,n,m,d,q;
int w[M],k[N];
vector<int> a[N],t[N];

void input() {
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i<=m;i++) { cin>>w[i];
    }
    for(int i = 1; i<=n;i++) {
        cin>>k[i];
        for(int j = 1; j<=k[i];j++) {
            int a1,t1;
            cin>>a1>>t1;
            a[i].push_back(a1);
            t[i].push_back(t1);

        }
    }
}

typedef pair<int, int> pii;

vector<pii > edges[D];
priority_queue<pii , vector<pii >, greater<pii > > que;

inline void add(int u,int v, int w){//cout<<"add"<<u<<"->"<<v<<" = "<<w<<endl;
    edges[u].push_back({w,v});
}

void build(){
    for(int i = 1; i<=n;i++) {
        for(int j1 = 0; j1<=k[i]-1;j1++) {
                for(int j2 = 0; j2<=k[i]-1;j2++) {
                    add(a[i][j1],a[i][j2],t[i][j1]+t[i][j2]);
                }
        }
    }
}

bool vis[D];
int dis[D];

void bfs(int u,int v){
    que.push({0,u});
    dis[u]=0;
    int cnt=0;
    while(!que.empty()){
        pii item=que.top();
        que.pop();
        int x=item.second;
        for(auto edge:edges[x]){
            int y=edge.second;
            if(!vis[y]){
                if(dis[y]>dis[x]+edge.first){

                    dis[y]=dis[x]+edge.first;
                    que.push({dis[y],y});
                }
                vis[y]=true;
            }
        }
    }
}

int solve(int u, int v){
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    while(!que.empty())que.pop();
    bfs(u,v);

    return dis[v]+w[u]+w[v];
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    input();
    build();
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<solve(u,v)<<endl;
    }

    return 0;
}
