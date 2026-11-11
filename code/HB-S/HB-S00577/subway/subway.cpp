#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int N=5e2+5;
typedef long long ll;
ll val[M];
int id,n,m,d,q;
vector<pair<int,ll>> G2[N];
vector<pair<int,ll>> bl[M];
ll mp[N][N],dis2[N][N],vis[N];
ll read(){
    ll x=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
struct node{
    int id;
    ll v;
    friend bool operator < (node a,node b){
        return a.v>b.v;
    }
};
priority_queue<node> Q;
void dij(int st){
    dis2[st][st]=0;
    for(int i=1;i<=n;i++) vis[i]=0;
    Q.push({st,0});
    while(Q.size()){
        node xl=Q.top();
        Q.pop();
        int u=xl.id;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto j:G2[u]){
            int v=j.first;
            ll w=j.second;
            if(dis2[st][v]>dis2[st][u]+w){
                dis2[st][v]=dis2[st][u]+w;
                Q.push({v,dis2[st][v]});
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    id=read(),n=read(),m=read(),d=read(),q=read();
    // cin>>id>>n>>m>>d>>q;
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=m;i++) val[i]=read();
    for(int i=1;i<=n;i++){
        int num;
        num=read();
        for(int j=1;j<=num;j++){
            int v,w;
            v=read(),w=read();
            bl[v].push_back({i,w});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:bl[i]){
            for(auto k:bl[i]){
                ll cw=j.second+k.second;
                int u=j.first,v=k.first;
                if(u==v) cw=0;
                mp[u][v]=min(mp[u][v],cw);
                mp[v][u]=min(mp[v][u],cw);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            G2[i].push_back({j,mp[i][j]});
        }
    }
    memset(dis2,0x3f,sizeof(dis2));
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<mp[i][j]<<" ";
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++) dij(i);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<dis2[i][j]<<" ";
    //     cout<<'\n';
    // }
    // for(int i=1;i<=n+m;i++){
    //     cout<<"{"<<i<<"}"<<'\n';
    //     for(auto j:G[i]) cout<<j.first<<" "<<j.second<<endl;
    // }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e16;
        for(int i=1;i<=n;i++){
            ll tmp1=1e16,tmp2=1e16;
            for(auto j:bl[x]){
                int v=j.first;
                ll w=j.second;
                tmp1=min(tmp1,dis2[v][i]+w);
            }
            for(auto j:bl[y]){
                int v=j.first;
                ll w=j.second;
                tmp2=min(tmp2,dis2[v][i]+w);
            }
            ans=min(ans,tmp1+tmp2);
        }
        cout<<ans+val[x]+val[y]<<'\n';
        // continue;
        // memset(dis,0x3f,sizeof(dis));
        // dis[x]=0;
        // DFS(x,0,y);
        // for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
        // cout<<'\n';
        // cout<<dis[y]+val[x]+val[y]<<'\n';
    }
    return 0;
}