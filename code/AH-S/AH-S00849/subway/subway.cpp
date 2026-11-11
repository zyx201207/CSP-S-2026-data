#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct edge{
    int v;
    long long w;
};
const int maxn=1000005;
vector<edge> g[maxn];
int cnt=0;
long long dis[maxn];
bool vis[maxn];
void dij(int st){
    for(int i=1;i<=cnt;i++) dis[i]=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=cnt;i++) vis[i]=0;
    dis[st]=0;
    while(true){
        int u=-1;
        for(int i=1;i<=cnt;i++){
            if(!vis[i]&&(u==-1||dis[i]<dis[u])){
                u=i;
            }
        }
      //      cout<<u<<endl;
        if(u==-1) break;
        vis[u]=1;
        for(edge e:g[u]){
            int v=e.v;
            long long w=e.w;
            if(!vis[v]&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        long long x;
        scanf("%lld",&x);
        g[i].push_back({i+m,x});
        g[i+m].push_back({i,x});
    }
    cnt=2*m+1;
    for(int i=1;i<=n;i++){
        int k,u;
        long long w;
        int lst=cnt;
        scanf("%d",&k);
        if(k==2){
            int v;
            long long w2;
            cin>>u>>w>>v>>w2;
            g[u+m].push_back({v+m,w+w2});
            g[v+m].push_back({u+m,w+w2});
            continue;
        }
        while(k--){
            scanf("%d %lld",&u,&w);
            g[u+m].push_back({cnt,w});
            g[cnt].push_back({u+m,w});
            if(lst<cnt){
                g[lst].push_back({cnt,0});
                g[cnt].push_back({lst,0});
                lst=cnt;
            }
            cnt++;
        }
    }
    cnt--;
    /*for(int i=1;i<=cnt;i++){
        cout<<i<<':';
        for(auto [v,w]:g[i]){
            cout<<" to"<<v<<" cst"<<w<<" "<<endl;
        }
    }*/
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        dij(x);
        printf("%lld\n",dis[y]);
    }
    return 0;
}
