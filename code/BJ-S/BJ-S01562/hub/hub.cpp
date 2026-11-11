#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+10;
int c,t,n,k,cnt;
vector<int> adj[MAXN];
int len,a[MAXN],fa[MAXN],mx[MAXN],sub[MAXN];
int dep[MAXN];
bool vis[MAXN];
void dfs0(int u){
    vis[u]=1;
    for(int v:adj[u]){
        if(vis[v]) continue;
        dep[v]=dep[u]+1;
        fa[v]=u;
        dfs0(v);
    }
    vis[u]=0;
}
int col;
void dfs1(int u){
    vis[u]=1;
    sub[u]=dep[u];
    mx[col]=max(mx[col],dep[u]);
    int p=dep[u];
    for(int v:adj[u]){
        if(vis[v]) continue;
        dep[v]=dep[u]+1;
        dfs1(v);
        sub[u]=max(sub[u],sub[v]);
        p=max(p,sub[v]);
    }
    vis[u]=0;
}
bool need[MAXN];
int dfs2(int u,int f){
    vis[u]=1;
    int tot=0;
    for(int v:adj[u]){
        if(vis[v]) continue;
        tot+=dfs2(v,f);
    }
    if(sub[u]>f) return tot+1;
    return 0;
}
bool chk(int f){
    //return 1;
    //<<"chk:"<<f<<'\n';
    int pl=cnt,pr=1;
    for(int i=1;i<=cnt;i++) need[i]=0;
    for(int i=1;i<=pl;i++){
        pl=min(pl,i+f-mx[i]);
        if(pl<i){
            pl=i;
            break;
        }
    }
    for(int i=cnt;i>=pr;i--){
        pr=max(pr,i-(f-mx[i]));
        if(pr>i){
            pr=i;
            break;
        }
    }
    if(!pl||!pr||pl>pr){
        return 1;
    }
    //cout<<pl<<' '<<pr<<'\n';
    need[pl]=need[pr]=1;
    int tot=0;
    bool all=1;
    for(int i=pl;i<=pr;i++){
        if(sub[i]>f){
            need[i]=1;
            vis[a[i+1]]=vis[a[i-1]]=1;
            tot+=dfs2(a[i],f);
            vis[a[i+1]]=vis[a[i-1]]=0;
        }
        else{
            if(need[i]) tot++;
            all=0;
        }
    }
    //cout<<tot<<'\n';
    if(tot>k) return 0;
    if(all) return 1;
    //cout<<'\n';
    int sz=0;
    for(int i=pl;i<=pr;i++){
        if(need[i]) continue;
        int beg=i,ed=i;
        for(int j=i;j<=pr;j++){
            if(need[j]) break;
            ed=j;
        }
        int ul=beg,ur=ed;
        for(int j=beg;j<=ed;j++){
            ul=max(ul,j-(f-mx[j]));
            ur=min(ur,j+(f-mx[j]));
        }
        i=ed;
        sz=max(sz,ur-ul-1);
    }
    for(int i=pl;i<=pr;i++){
        if(!need[i]) tot++;
    }
    tot-=sz+1;
    if(tot<=k) return 1;
    return 0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;len=cnt=0;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            a[i]=fa[i]=mx[i]=sub[i]=dep[i]=vis[i]=0;
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dep[1]=1;
        dfs0(1);
        int s=1,t=1;
        for(int i=1;i<=n;i++){
            if(dep[i]>dep[s]) s=i;
        }
        dep[s]=1;
        dfs0(s);
        for(int i=1;i<=n;i++){
            if(dep[i]>dep[t]) t=i;
        }
        int now=t;
        a[++cnt]=t;
        while(now!=s){
            now=fa[now];
            a[++cnt]=now;
        }
        if(k==n){
            cout<<0<<'\n';
            return 0;
        }
        if(k==0){
            cout<<cnt-1<<'\n';
            return 0;
        }
        //cout<<"ok\n";
        //for(int i=1;i<=cnt;i++) cout<<a[i]<<' ';
        //cout<<'\n';

        for(int i=1;i<=cnt;i++){
            vis[a[i-1]]=vis[a[i+1]]=1;
            col=i;dep[a[i]]=0;
            dfs1(a[i]);
            vis[a[i-1]]=vis[a[i+1]]=0;
        }


        //for(int i=1;i<=cnt;i++) cout<<ml[i]<<' '<<mx[i]<<' '<<sub[a[i]]<<'\n';

        int l=1,r=cnt,mid;
        while(l<r){
            //cout<<l<<' '<<r<<'\n';
            mid=l+r>>1;
            if(chk(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<'\n';
        //return 0;
    }
    return 0;
}
