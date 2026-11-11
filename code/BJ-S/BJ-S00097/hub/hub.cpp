#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;

struct node{
    int v,nxt;
}e[MAXN<<2];
int n,k;

int tot=0,h[MAXN],dep[MAXN],cnt[MAXN],vis[MAXN],c[MAXN],lll[MAXN],f[MAXN][20],col[MAXN],s,t;
void addEdge(int u,int v){
    ++tot;
    e[tot].v=v;e[tot].nxt=h[u];h[u]=tot;
}

void dfs(int u,int fa){
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)   continue;
        f[v][0]=u;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}

void dfs2(int u,int fa,int x){
    //f[u]=fa;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)   continue;
        dfs2(v,u,x);
        cnt[u]=max(cnt[u],cnt[v]+1);
        c[u]=max(c[u],c[v]);
        if(cnt[u]==x)   cnt[u]=0,col[u]=1,c[u]=1;
    }
}
int ans1=0,dec1=0;
void dfs3(int u,int fa){
    if(!vis[u]) ans1++;
    vis[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa || c[v]==0)   continue;
        dfs3(v,u);
    }
}

int getLCA(int x,int y){
    if(dep[x]>dep[y])   swap(x,y);
    int d=dep[y]-dep[x];
    for(int j=19;j>=0;j--){
        if(d&(1<<j))    y=f[y][j];
    }
    if(x==y)    return x;
    for(int j=19;j>=0;j--){
        if(f[x][j]!=f[y][j]){
            x=f[x][j];
            y=f[y][j];
        }
    }
    return f[x][0];
}

int check(int x){
    memset(col,0,sizeof(col));
    memset(vis,0,sizeof(vis));
    dfs2(s,0,x);
    //lca
    int lca=t;
    for(int i=1;i<=n;i++){
        if(col[i])  lca=getLCA(lca,i);
    }
    ans1=0,dec1=0;
    dfs3(lca,0);
    memset(lll,0,sizeof(lll));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!col[i]|| !col[j])   continue;
            int kkk=getLCA(i,j);
            if(lll[kkk]==0) lll[kkk]=dep[i]+dep[j]-2*dep[kkk]-1;
            else lll[kkk]=min(lll[kkk],dep[i]+dep[j]-2*dep[kkk]-1);
        }
    }
    for(int i=1;i<=n;i++)   dec1=max(dec1,lll[i]);
    if(ans1-dec1>x)   return 0;
    return 1;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cc,T;
    cin>>cc>>T;
    while(T--){
        cin>>n>>k;
        memset(h,0,sizeof(h));tot=0;
        memset(f,0,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        memset(c,0,sizeof(c));
        memset(col,0,sizeof(col));
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            addEdge(u,v);
            addEdge(v,u);
        }
        memset(dep,0,sizeof(dep));
        dfs(1,0);
        int maxx=0;
        for(int i=1;i<=n;i++){
            if(maxx<dep[i]) maxx=dep[i],s=i;
        }
        memset(dep,0,sizeof(dep));
        dfs(s,0);
        maxx=0;
        for(int i=1;i<=n;i++){
            if(maxx<dep[i]) maxx=dep[i],t=i;
        }
        if(k==n){
            cout<<0<<'\n';
            continue;
        }
        if(k==0){
            cout<<maxx<<'\n';
            continue;
        }

        for(int j=1;j<=19;j++){
            for(int i=1;i<=n;i++){
                f[i][j]=f[f[i][j-1]][j-1];
            }
        }

        int l=1,r=maxx;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid))  r=mid;
            else l=mid+1;
        }
        cout<<l-1<<'\n';
    }

    return 0;
}
