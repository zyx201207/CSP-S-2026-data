#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct Node{
    int a,t;
};
vector<Node>v[100010];
int vis[100010];
int w[100010];
int mint=99999;
void bfs(int x,int y){
    queue<Node>q;
    q.push({x,0});
    vis[x]=1;
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        for(int i=0;i<v[now.a].size();i++){
            Node nex=v[now.a][i];
            if(vis[nex.a]==0){
                vis[nex.a]=1;
                q.push({nex.a,nex.t+now.t});
            }
        }
        if(vis[x]==1){
            mint=now.t;
            return;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
            int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            if(j>=2){
                v[a].push_back({a-1,0});
                v[a-1].push_back({a,0});
                v[a].push_back({-a,t});
                v[-a].push_back({a,t});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x1,y1;
        cin>>x1>>y1;
        mint=99999;
        bfs(x1,y1);
        cout<<mint<<"\n";
    }
    return 0;
}
