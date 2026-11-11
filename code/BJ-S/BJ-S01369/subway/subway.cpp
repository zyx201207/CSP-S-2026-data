#include<bits/stdc++.h>
using namespace std;
int t[505];
int sum;
struct node{
    int station;
    int time;
};
struct Node{
    int x;
    int time;
};
vector<node>v[505];
bool vis[505][505];
queue<Node>q;
void bfs(int x,int y){
    sum=INT_MAX;
    memset(vis,0,sizeof(vis));
    q.push({x,t[x]});
    for(auto i:v[x]){
        vis[x][i.station]=1;
        vis[i.station][x]=1;
        q.push({i.station,t[x]+i.time});
    }
    while(!q.empty()){
        Node f=q.front();
        q.pop();
        if(f.x==y)sum=min(sum,f.time+t[y]);
        for(auto i:v[f.x]){
            for(auto j:v[i.station]){
                if(vis[i.station][j.station])continue;
                Node N={i.station,f.time+i.time+j.time};
                vis[i.station][j.station]=1;
                vis[j.station][i.station]=1;
                q.push(N);
            }

        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>t[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            v[i].push_back({a,t});
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        bfs(x,y);
        cout<<sum<<'\n';
    }
    return 0;
}
