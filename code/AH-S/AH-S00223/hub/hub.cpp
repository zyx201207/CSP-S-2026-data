#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,k;
vector<int> e[105];
int vis[105];
int dis[105][105];
int take[105],in[105];
int ans;

void dfs(int s,int u,int d){
    vis[u]=1;
    dis[s][u]=d;
    for(auto v:e[u])
        if(vis[v]==0) dfs(s,v,d+1);
}

void dfs2(int u){
    vis[u]=1;
    for(auto v:e[u])
        if(vis[v]==0 && in[v]==1) dfs2(v);
}

bool check(){
    memset(vis,0,sizeof(vis));
    int sum=0;
    for(int i=1;i<=k;i++)
        if(vis[i]==0 && in[i]){
            dfs2(i);
            sum++;
        }
    if(sum<=2) return 1;
}

int dmax(){
    int mx=0;
    for(int i=1;i<=n;i++){
        int mn=1e9;
        for(int j=1;j<=k;j++) mn=min(mn,dis[i][take[j]]);
        mx=max(mx,mn);
    }
    return mx;
}

void build(int last,int siz){
    if(siz==k){
        if(check()) ans=min(ans,dmax());
        return;
    }
    for(int i=last+1;n-i>=k-siz-1;i++){
        take[siz+1]=i;
        in[i]=1;
        build(i,siz+1);
        in[i]=0;
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    int c,T; cin>>c>>T;
    while(T--){
        ans=1e9;

        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v; cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i,i,0);
        }

        build(0,0);
        cout<<ans<<'\n';
    }

    return 0;
}
