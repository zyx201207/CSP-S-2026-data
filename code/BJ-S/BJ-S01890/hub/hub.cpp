#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7,LG=22;
int c,t;
int n,k;
vector<int>tr[N];
int dep[N],fa[LG][N];
void dfs(int u,int f){
    fa[0][u]=f;
    dep[u]=dep[f]+1;
    for(int j=1;j<LG;j++)
        fa[j][u]=fa[j-1][fa[j-1][u]];
    for(int v:tr[u]){
        if(v==f)continue;
        dfs(v,u);
    }
}
inline int lca(int u,int v){
    if(u==v)return v;
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=LG-1;~i;i--)
        if(d&(1<<i))u=fa[i][u];
    if(u==v)return u;
    for(int i=LG-1;~i;i--)
        if(fa[i][v]^fa[i][u])u=fa[i][u],v=fa[i][v];
    return fa[0][u];
}
inline int dis(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
}
bool flg[N];
int ff[N];
int find(int x){
    return x==ff[x]?x:ff[x]=find(ff[x]);
}
inline bool chk(){
    for(int i=1;i<=n;i++)ff[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(flg[i]&flg[j]){
                ff[find(i)]=find(j);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(flg[i]&&ff[i]==i)++cnt;
    }
    return cnt<=2;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)tr[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            tr[u].push_back(v),tr[v].push_back(u);
        }
        dfs(1,0);
        int ss=N;
        if(n<=10){
            for(int S=0;S<(1<<n);S++){
                if(__builtin_popcount(S)==k){
                    for(int i=1;i<=n;i++){
                        flg[i]=0;
                        if(S&(1<<(i-1)))flg[i]=1;
                    }
                    if(chk()){
                        int ans=0;
                        for(int i=1;i<=n;i++){
                            int res=N;
                            for(int j=1;j<=n;j++){
                                if(flg[j])res=min(res,dis(i,j));
                            }
                            ans=max(ans,res);
                        }
                        ss=min(ss,ans);
                    }
                }
            }
            cout<<ss<<'\n';
        }
    }
    return 0;
}