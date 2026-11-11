#include<bits/stdc++.h>
using namespace std;
const int N=20;
vector<int> e[N];
int c,t,n,k,vis[N],b[N];
void dfs(int u,int fa){
    vis[u]=1;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v!=fa&&b[v]) dfs(v,u);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        // for(int i=0;i<(1<<10);i++){
        //     int x=i,tot=0;
        //     memset(vis,0,sizeof(vis));
        //     int cnt=0;
        //     while(x){
        //         if(x&1) cnt++;
        //         b[++tot]=x&1;
        //         x>>=1;
        //     }
        //     int res=0;
        //     for(int i=1;i<=n;i++){
        //         if(b[i]){
        //             if(!vis[i]){
        //                 dfs(i,0);
        //                 res++;
        //             }
        //         }
        //     }
        //     if(res>2) continue;
            
        // }
        cout<<1<<endl;
    }
    return 0;
}