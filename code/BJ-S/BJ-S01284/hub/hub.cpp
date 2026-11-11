#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=20,N1=1e3+10,INF=1e9;
int c,T,n,k,f[N][M+1],dep[N],Lca[N1][N1],dis[N1][N1];
int a[N],la,ans,dep_r[N];
vector<int> g[N];
void dfs(int u,int fu){
    f[u][0]=fu;
    dep[u]=dep[fu]+1;
    for(int i=1;i<=M;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(auto v:g[u]){
        if(v==fu)continue;
        dfs(v,u);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    if(dep[x]>dep[y]){
        for(int i=M;i>=0;i--)
            if(dep[f[x][i]]>=dep[y])
                x=f[x][i];
    }
    if(x!=y){
        for(int i=M;i>=0;i--)
            if(f[x][i]!=f[y][i])
                x=f[x][i],y=f[y][i];
        x=f[x][0];
    }
    return x;
}
inline int fa(int x,int l){
    for(int i=0;i<=M&&l;i++){
        if(l&(1<<i))x=f[x][i];
    }
    return x;
}
inline int mid(int u,int v){
    if(dep[u]>dep[v])return fa(u,dis[u][v]>>1);
    return fa(v,dis[u][v]>>1);
}
inline int mid2(int u,int v,int dis){
    if(dep[u]>dep[v])return fa(u,dis>>1);
    return fa(v,dis>>1);
}
inline pair<int,int> check(int a[],int la){
    int mxd=0,mxu=0,mxv=0;
    for(int u=1;u<=n;u++){
        int du=INF,dv=0;
        for(int v=1;v<=la;v++){
            if(dis[u][a[v]]<du){
                du=dis[u][a[v]];
                dv=a[v];
            }
        }
        if(du>mxd){
            mxd=du;
            mxu=u;
            mxv=dv;
        }
    }
    // cout<<"+ "<<mxv<<"-"<<mxu<<":"<<mxd<<'\n';
    if(dep[Lca[mxu][mxv]]<dep[mxv]){
        return {mxd,f[mxv][0]};
    }
    return {mxd,fa(mxu,dep[mxu]-dep[mxv]-1)};
}
inline pair<int,pair<int,int> > check2(int u,int v){
    int mxd=0,mxu=0,mxv=0,newu,newv;
    for(int t=1;t<=n;t++){
        int du=INF,dv=0;
        int dtu=dep[t]+dep[u]-2*dep[lca(t,u)];
        if(dtu<du){
            du=dtu;
            dv=u;
        }
        dtu=dep[t]+dep[v]-2*dep[lca(t,v)];
        if(dtu<du){
            du=dtu;
            dv=v;
        }
        if(du>mxd){
            mxd=du;
            mxu=t;
            mxv=dv;
        }
    }
    // cout<<"+ "<<mxv<<"-"<<mxu<<":"<<mxd<<'\n';
    int newx=0;
    if(dep[lca(mxu,mxv)]<dep[mxv]){
        newx=f[mxv][0];
    }
    else newx=fa(mxu,dep[mxu]-dep[mxv]-1);
    if(mxv==u)u=newx;
    else v=newx;
    return {mxd,{u,v}};
}
void solve1(){
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++){
            Lca[i][i]=i;
            for(int j=i+1;j<=n;j++){
                Lca[i][j]=Lca[j][i]=lca(i,j);
                dis[i][j]=dis[j][i]=dep[i]+dep[j]-2*dep[Lca[i][j]];
            }
        }
        ans=INF;
        for(int i=1;i<=n;i++){
            cout<<i<<'\n';
            for(int j=i+1;j<=n;j++){
                la=2,a[1]=i,a[2]=j;
                // cout<<i<<"&"<<j<<":"<<'\n';
                bool ok=1;
                while(la<k){
                    auto [d,u]=check(a,la);
                    if(d-(k-la)>=ans){
                        ok=0;
                        // cout<<d-(k-la)<<">="<<ans<<'\n';
                        break;
                    }
                    a[++la]=u;
                    // cout<<"->"<<a[la]<<'\n';
                }
                if(ok)ans=min(ans,check(a,la).first);
            }
        }
        cout<<ans<<'\n';
    }
}
void solve2(){
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        int mxd=0,mxu=0,mxv=0;
        for(int i=1;i<=n;i++){
            Lca[i][i]=i;
            for(int j=i+1;j<=n;j++){
                Lca[i][j]=Lca[j][i]=lca(i,j);
                dis[i][j]=dis[j][i]=dep[i]+dep[j]-2*dep[Lca[i][j]];
                if(dis[i][j]>mxd){
                    mxd=dis[i][j];
                    mxu=i;
                    mxv=j;
                }
            }
        }
        ans=INF;
        int md=mid(mxu,mxv),u=mid(mxu,md),v=mid(mxv,md);
        vector<int> ax,ay;
        for(int i=1;i<=n;i++){
            if(dis[i][u]<=1) ax.push_back(i);
        }
        for(int i=1;i<=n;i++){
            if(dis[i][v]<=1) ay.push_back(i);
        }
        for(auto i:ax){
            for(auto j:ay){
                la=2,a[1]=i,a[2]=j;
                // cout<<i<<"&"<<j<<":"<<'\n';
                bool ok=1;
                while(la<k){
                    auto [d,u]=check(a,la);
                    if(d-(k-la)>=ans){
                        ok=0;
                        // cout<<d-(k-la)<<">="<<ans<<'\n';
                        break;
                    }
                    a[++la]=u;
                    // cout<<"->"<<a[la]<<'\n';
                }
                if(ok)ans=min(ans,check(a,la).first);
            }
        }
        cout<<ans<<'\n';
    }
}
void dfs_1(int u,int fu){
    dep_r[u]=dep_r[fu]+1;
    for(auto v:g[u]){
        if(v==fu)continue;
        dfs_1(v,u);
    }
}
void solve3(){
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        int mxd=0,mxu=0,mxv=0;
        for(int i=1;i<=n;i++){
            if(dep[i]>dep[mxu]) mxu=i;
        }
        dfs_1(mxu,0);
        for(int i=1;i<=n;i++){
            if(dep_r[i]>dep_r[mxv]) mxv=i;
        }
        ans=INF;
        int md=mid2(mxu,mxv,dep_r[mxv]),u=mid2(mxu,md,dep_r[mxv]>>1),v=mid2(mxv,md,dep_r[mxv]>>1);
        while(1){
            auto [d,nw]=check2(u,v);
            if(check2(nw.first,nw.second).first>d) break;
            else{
                u=nw.first;
                v=nw.second;
            }
        }
        cout<<check2(u,v).first<<'\n';
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    if(c<=3){
        solve1();
    }else if(c==7||c==11||c==12){
        solve3();
    }else{
        solve2();
    }
    
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/