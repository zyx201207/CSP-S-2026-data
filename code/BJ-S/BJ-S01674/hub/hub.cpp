#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
int c,t,n,m,k,dis[15][15],flg[15],ans,eu[1000005],ev[1000005];
vector<int>e[1000005];
queue<int>q;
void bfs(int x){
    memset(dis[x],0x3f,sizeof dis[x]);
    q.push(x);dis[x][x]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:e[u]){
            if(dis[x][v]==0x3f3f3f3f){
                dis[x][v]=dis[x][u]+1;
                q.push(v);
            }
        }
    }
}
// int fa[15];
// void init(){for(int i=1;i<=n;i++)fa[i]=i;}
// int rt(int x){return x==fa[x]?x:fa[x]=rt(fa[x]);}
// int unite(int x,int y){
//     int fax=rt(x),fay=rt(y);
//     if(fax!=fay){
//         fa[fax]=fay;
//         return 1;
//     }
//     return 0;
// }
void dfs(int x,int cnt){
    if(x==n+1){
        if(cnt!=k)return;
        int tot=0;
        for(int i=1;i<n;i++)if(flg[eu[i]]&&flg[ev[i]])tot++;
        if(tot<k-2)return;
        // cout<<"tot="<<tot<<"\n";
        tot=0;
        for(int i=1;i<=n;i++){
            int mn=n;
            for(int j=1;j<=n;j++)
                if(flg[j])mn=min(mn,dis[i][j]);//,cout<<i<<" "<<j<<":"<<dis[i][j]<<"\n";
            tot=max(tot,mn);
        }
        // if(tot==1){
        // for(int i=1;i<=n;i++)cout<<flg[i]<<" ";
        // cout<<":"<<tot<<"\n";
        // }
        ans=min(ans,tot);
        return;
    }
    flg[x]=1;dfs(x+1,cnt+1);
    flg[x]=0;dfs(x+1,cnt);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            e[u].pb(v),e[v].pb(u);
            eu[i]=u,ev[i]=v;
        }
        if(c==13||c==14){
            m=(n-1)/2;
            if(k==n)cout<<0<<"\n";
            else if(k>=m)cout<<1<<"\n";
            else cout<<(m-k)/2+1<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++)bfs(i);
        ans=n;
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}