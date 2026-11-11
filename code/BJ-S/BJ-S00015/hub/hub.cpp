#include <bits/stdc++.h>
using namespace std;

const int N=20;
int c,T,n,k,a[N],d[N],ans=1e9;
bool vis[N],bel[N];
vector <int> e[N];

void dfs2(int u,int fa){
    d[u]=min(d[u],d[fa]+1);
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v==fa) continue;
        dfs2(v,u);
    }
}

int solve(){
    int res=0;
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=k;i++){
        d[a[i]]=0;
        dfs2(a[i],0);
    }
    for(int i=1;i<=n;i++){
        res=max(res,d[i]);
    }
    return res;
}

void dfs(int u,int fa){
    vis[u]=1;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v!=fa && bel[v]) dfs(v,u);
    }
}

bool check(){
    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=k;i++){
        if(!vis[a[i]]){
            dfs(a[i],0);
            cnt++;
        }
    }
    return cnt<=2;
}

void s(int x,int m){
    if(m==k+1){
        if(check()){
            ans=min(ans,solve());

        }else{
            return;
        }
    }
    for(int i=x;i<=n;i++){
        a[m]=i;
        bel[i]=1;
        s(i+1,m+1);
        a[m]=0;
        bel[i]=0;
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        s(1,1);
        cout<<ans<<'\n';
    }
}
