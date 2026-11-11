#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k;
vector<int>G[N];
struct node{
    int u,d;
};
queue<node>q;
int dis[N],dis2[N];
void BFS(int s){
    q.push({s,0});
    while(!q.empty()){
        int u=q.front().u,d=q.front().d;
        dis[u]=d;
        q.pop();
        for(int v:G[u]){
            if(d+1<dis[v])q.push({v,d+1});
        }
    }
}
void BFS2(int s){
    q.push({s,0});
    while(!q.empty()){
        int u=q.front().u,d=q.front().d;
        dis2[u]=d;
        q.pop();
        for(int v:G[u]){
            if(d+1<dis2[v])q.push({v,d+1});
        }
    }
}
int main(){
    freopen("hub.in","r",stdin)
    freopen("hub.out","w",stdout)
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,u,v;i<=n-1;i++){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                BFS(i);
                BFS2(j);
                for(int i=1;i<=n;i++)dis[i]=min(dis[i],dis2[i]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,dis[i]);
        cout<<ans<<endl;
    }
    return 0;
}
