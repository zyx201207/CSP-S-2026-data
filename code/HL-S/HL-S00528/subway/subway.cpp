#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q;//n xianlu,m zhan
int w[514114];
struct abcd{
    int v,w;
};
int e[514][514];//xian lu
int dis[514][514];
struct abcde{
    int a,t;
};
vector<abcde> b[514];
int vis[514114];
/*int slove(int id1,int id2){
    
    int ans=1e18;
    for(int i=0;i<b[id2].size();i++){
        if(vis[b[id2][i].a]) ans=min(ans,vis[b[id2][i].a]+b[id2][i].t);
    }
    
    return ans;
}*/
bool cmp(abcde x,abcde y){
    return x.a<y.a;
}
struct abcdef{
    int id,num;
};
vector<abcdef> c[514114];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            b[i].push_back({x,y});
            c[x].push_back({i,y});
        }
    //    sort(b[i].begin(),b[i].end(),cmp);
    }
    for(int id1=1;id1<=n;id1++){
        for(int i=0;i<b[id1].size();i++){
            vis[b[id1][i].a]=b[id1][i].t;
        }
        for(int id2=id1+1;id2<=n;id2++){
            int ans=1e18;
            for(int i=0;i<b[id2].size();i++){
                if(vis[b[id2][i].a]) ans=min(ans,vis[b[id2][i].a]+b[id2][i].t);
            }
            e[id1][id2]=e[id2][id1]=ans;
            dis[id1][id2]=dis[id2][id1]=e[id1][id2];
        }
        for(int i=0;i<b[id1].size();i++) vis[b[id1][i].a]=0;
        dis[id1][id1]=0;
    }
   /* for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<e[i][jfor(int i=0;i<b[id1].size();i++) vis[b[id1][i].a]=0;]<<" ";cout<<"\n";
    }cout<<"\n";*/
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
   /* for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";cout<<"\n";
    }cout<<"\n";*/
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=1e18;
        for(int i=0;i<c[u].size();i++){
            for(int j=0;j<c[v].size();j++){
                ans=min(ans,dis[c[u][i].id][c[v][j].id]+c[u][i].num+c[v][j].num);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}