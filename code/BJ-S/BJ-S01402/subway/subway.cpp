#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,t;
}k[505][55];
struct edge{
    int e,w;
};
int l[505];
int c,n,m,d,q,w[500005],dis[500005];
vector<edge> g[500005];
void bfs(int s){
    queue<int> q;
    q.push(s);
    memset(dis,-1,sizeof(dis));
    dis[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto [e,w]:g[x]){
            if(dis[e]!=-1&&dis[e]<=dis[x]+w) continue;
            q.push(e);
            dis[e]=dis[x]+w;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        l[i]=x;
        for(int j=1;j<=x;j++) cin>>k[i][j].a>>k[i][j].t;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=l[i];j++){
            for(int x=1;x<j;x++){
                g[k[i][j].a].push_back({k[i][x].a,k[i][j].t+k[i][x].t});
                g[k[i][x].a].push_back({k[i][j].a,k[i][j].t+k[i][x].t});
            }
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        bfs(l);
        cout<<dis[r]+w[l]+w[r]<<endl;
    }
    return 0;
}
