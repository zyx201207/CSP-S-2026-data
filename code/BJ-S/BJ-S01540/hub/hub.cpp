#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int c,t,n,k,ans;
int eu[25],ev[25],g[25][25],dis[25][25],fa[25],chs[25];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x!=y)fa[x]=y;
}
void calc(int x){
    int sc=0;
    for(int i=0;i<n;i++)
        if((x>>i)&1)chs[sc++]=i;
    if(sc!=k)return;
    for(int i=0;i<n;i++)fa[i]=i;
    for(int i=0;i<n-1;i++){
        int u=eu[i],v=ev[i];
        if(((x>>u)&1)&&((x>>v)&1))unite(u,v);
    }
    int cnt=0;
    for(int i=0;i<sc;i++){
        int v=chs[i];
        if(find(v)==v)++cnt;
    }
    if(cnt>2)return;
    int res=0;
    for(int i=0;i<n;i++){
        int best=inf;
        for(int j=0;j<sc;j++)best=min(best,dis[i][chs[j]]);
        res=max(res,best);
        if(res>=ans)return;
    }
    ans=min(ans,res);
}
void dfs(int u,int cnt,int msk){
    if(cnt==k){
        calc(msk);
        return;
    }
    if(u==n)return;
    if(cnt+(n-u)<k)return;
    dfs(u+1,cnt,msk);
    dfs(u+1,cnt+1,msk|(1<<u));
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        memset(g,0,sizeof(g));
        for(int i=0;i<n-1;i++){
            int u,v;cin>>u>>v;
            eu[i]=--u;ev[i]=--v;
            g[u][v]=g[v][u]=1;
        }
        if(k==n){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)dis[i][j]=inf;
        for(int i=0;i<n;i++){
            queue<int> q;q.push(i);
            dis[i][i]=0;
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int j=0;j<n;j++){
                    if(g[u][j]&&dis[i][j]==inf){
                        dis[i][j]=dis[i][u]+1;
                        q.push(j);
                    }
                }
            }
        }
        ans=inf;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
//我常常追忆过去
//何意味下周期中我还没复习