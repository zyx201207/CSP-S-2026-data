#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>g[N];
bool vis[N];
int ans,dist[N];
void dfs2(int u){
    vis[u]=true;
    for(auto node:g[u]){
        if(!vis[node])
            dfs2(node);
    }
}
void bfs(int s,int n){
    for(int i=1;i<=n;i++)
        dist[i]=INT_MAX;
    dist[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto node:g[u]){
            if(dist[u]+1<dist[node]){
                dist[node]=dist[u]+1;
                q.push(node);
            }
        }
    }
}
void dfs(int u,int n,vector<int>b){
    if(u==n+1){
        int cnt=0;
        for(auto x:b){
            if(!vis[x]){
                cnt++;
                dfs2(x);
            }
        }
        if(cnt<=2){
            for(int i=1;i<=n;i++){
                bfs(i,n);
//                cout<<i<<": ";
//                for(auto x:b)
//                    cout<<dist[x]<<" ";
//                cout<<endl;
                int d=INT_MAX;
                for(auto x:b)
                    d=min(d,dist[x]);
                if(d!=INT_MAX)
                    ans=max(ans,d);
            }
        }
        return;
    }
    dfs(u+1,n,b);
    b.push_back(u);
    dfs(u+1,n,b);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=0;
        dfs(1,n,{});
        printf("%d\n",ans);
    }
    return 0;
}
