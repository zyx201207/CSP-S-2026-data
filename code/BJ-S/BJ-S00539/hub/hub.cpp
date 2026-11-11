#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//#define int long long
typedef long long ll;
const int N=1e6+7;
int T,n,k;
int dis[N],dep[N];
bool vis[N],in[N];
vector<int>g[N];
int ans;
void bfs(int s,bool op){
    queue<int>q;
    vis[s]=1;
    memset(dis,-1,sizeof dis);
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            bool ok=(op==1?in[v]:1);
            if(dis[v]==-1&&ok){
                dis[v]=dis[u]+1;
                q.push(v);
                vis[v]=1;
            }
        }
    }
}

bool chk(){
    memset(vis,0,sizeof vis);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(in[i]&&(!vis[i]))++cnt,bfs(i,1);
    }
    //for(int i=1;i<=n;i++)cout<<in[i]<<" ";
    //cout<<"\n"<<cnt<<"\n\n";
    if(cnt>2||cnt==0)return 0;
    return 1;
}
int getdis(){
    int res=0;
    for(int i=1;i<=n;i++){
        if(in[i])continue;
        bfs(i,0);
        int mn=n+1;
        for(int j=1;j<=n;j++){
            if(in[j])mn=min(mn,dis[j]);
        }
        res=max(res,mn);
    }/*
    if(res==1){
        for(int i=1;i<=n;i++)cout<<in[i]<<" ";
        cout<<"\n\n";
    }*/
    return res;
}
void dfs(int nw,int c){
    //cout<<n<<" "<<nw<<" "<<c<<"\n";
    if(nw==n+1){
        //for(int i=1;i<=n;i++)cout<<in[i]<<" ";
        //cout<<"\nc="<<c<<"\n\n";
        if(c<=k&&chk())ans=min(ans,getdis());
        return ;
    }
    dfs(nw+1,c);
    in[nw]=1;
    dfs(nw+1,c+1);
    in[nw]=0;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        ans=n+1;
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
