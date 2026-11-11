#include<bits/stdc++.h>
using namespace std;

const int N=1e6+7;
int n,k;
int f[N],ans,vis[N],dis[N];

vector<int>tr[N];

void zdjd(int u,int fa){
    vis[u]=1;
    for(int v:tr[u]){
        if(v==fa) continue;
        if(f[v]) zdjd(v,u);
    }
}

void cxy(int u,int fa,int dep){
    dis[u]=min(dis[u],dep);
    for(int v:tr[u]){
        if(v==fa) continue;
        if(!f[v]) cxy(v,u,dep+1);
    }
}

void kskbl(){
    int mj=0;
    for(int i=1;i<=n;i++){
        if(f[i]&&!vis[i]){
            zdjd(i,0);
            mj++;
        }
    }
    if(mj>2) return;
    for(int i=1;i<=n;i++) dis[i]=1e9;
    for(int i=1;i<=n;i++){
        if(f[i]) cxy(i,0,0);
    }
    int sl=0;
    for(int i=1;i<=n;i++){
        sl=max(sl,dis[i]);
    }
    ans=min(ans,sl);
}

void dfs(int u,int c){
    if(c>k) return;
    if(u>n){
        if(c==k){
            for(int i=1;i<=n;i++) vis[i]=0;
            kskbl();
        }
        return;
    }
    f[u]=1;
    dfs(u+1,c+1);
    f[u]=0;
    dfs(u+1,c);
}

int main(){

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int C,T;
    cin>>C>>T;

    while(T--){
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;i++) {tr[i].clear();f[i]=0;}

        int u,v;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }

        dfs(1,0);

        cout<<ans<<'\n';
    }

    return 0;
}
