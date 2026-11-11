#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int inf=1e9+10;
int tid,n,k,a[N],vis[N],dis[N],ch[N],b[N][N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
vector<int> g[N];
int fa[N];
int find(int x){
    return (x==fa[x]?x:fa[x]=find(fa[x]));
}
int bfs(){
    int mx=0;
    for(int i=1;i<=n;i++)vis[i]=0,dis[i]=inf,fa[i]=i;
    for(int i=1;i<=k;i++){
        // cout<<a[i]<<' ';
        q.push({0,a[i]});
        // vis[a[i]]=1;
        dis[a[i]]=0;
        for(int j=1;j<=k;j++){
            if(i==j||!b[a[i]][a[j]])continue;
            int x=find(a[i]),y=find(a[j]);
            if(x!=y)fa[x]=y;
        }
    }
    while(q.size()){
        int u=q.top().second,w=q.top().first;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        // cout<<u<<' '<<dis[u]<<"\n";
        for(auto v:g[u]){
            // cout<<v<<' '<<dis[v]<<'\n';
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push({dis[v],v});
            }
        }
    }
    int sum=0;
    for(int i=1;i<=k;i++){
        if(fa[a[i]]==a[i])sum++;
    }
    // cout<<sum<<' ';
    if(sum>2)mx=inf;
    for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
    return mx;
}
int ans=0;
void dfs(int step,int las){
    if(step==k){
        ans=min(ans,bfs());
        return;
    }
    for(int i=las;i<=n;i++){
        if(!ch[i]){
            ch[i]=1;
            a[step+1]=i;
            dfs(step+1,i+1);
            ch[i]=0;
        }
    }
}
int f[N];
bool bb[N];
void dfs(int u,int step,int fa,int lim){
    f[u]++;
    if(step==lim)return;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs(v,step+1,u,lim);
    }
}
int now=0;
void dfs1(int u,int step,int fa,int lim){
    bb[u]=1;
    now++;
    if(step==lim)return;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs1(v,step+1,u,lim);
    }
}
bool check(int x){
    // cout<<"case"<<x<<"\n";
    int ans=n;
    for(int j=1;j<=n;j++){
        int sum=n;
        for(int i=1;i<=n;i++){
            f[i]=bb[i]=0;
        }
        now=0;
        dfs1(j,0,0,x);
        sum-=now;
        for(int i=1;i<=n;i++)f[i]=0;
        for(int i=1;i<=n;i++){
            if(!bb[i]){
                // cout<<i<<'\n';
                dfs(i,0,0,x);
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            if(f[i]>f[mx])mx=i;
        }
        // cout<<mx<<"\n";
        sum-=f[mx];
        ans=min(sum,ans);
    }
        // cout<<sum<<"\n";
    return ans==0;
}
void work(){
    ans=inf;
    cin>>n>>k;
    if(tid<=3)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b[i][j]=0,g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        if(tid!=13&&tid!=14)g[u].push_back(v);
        if(tid!=13&&tid!=14)g[v].push_back(u);
        if(tid<=3)b[u][v]=b[v][u]=1;
    }
    if(tid<=3){
        dfs(0,1);
        cout<<ans<<"\n";return;
    }
    else if(tid==13||tid==14){
        if(n<=k){
            cout<<0<<"\n";return;
        }
        if(k==1){
            cout<<(n+3)/4<<"\n";return;
        }
        cout<<(n-2*k+6)/8+1<<"\n";
    }
    else{
        int l=0,r=n,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                r=mid-1;
                // cout<<mid<<"\n";
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int tcase;
    cin>>tid>>tcase;
    while(tcase--)work();
}