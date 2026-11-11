#include<iostream>
using namespace std;

const int MAXN=1e6+5,MAXL=25;
int c,t,n,k,cnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
int dep[MAXN],f[MAXN][MAXL];
int tot,ans,id[MAXN];
bool plan[MAXN];

void add(int x,int y){
    to[++cnt]=y;
    nxt[cnt]=head[x];
    head[x]=cnt;
}
void dfs(int x,int fa){
    f[x][0]=fa;
    for(int i=1;i<=20;i++)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=nxt[i]){
        int y=to[i];
        if(y==fa)continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[x]-dep[y]>=(1<<i))
            x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int dist(int x,int y){
    int z=lca(x,y);
    return dep[x]+dep[y]-2*dep[z];
}

void fll(int x){
    id[x]=tot;
    for(int i=head[x];i;i=nxt[i]){
        int y=to[i];
        if(id[y])continue;
        if(!plan[y])continue;
        fll(y);
    }
}
void sel(int x,int cnt){
    if(cnt>k)return;
    if(x>n){
        if(cnt==k){
            tot=0;
            for(int i=1;i<=n;i++)id[i]=0;
            for(int i=1;i<=n;i++)
                if(!id[i]&&plan[i])tot++,fll(i);
            if(tot>2)return;
            int mx=0;
            for(int i=1;i<=n;i++){
                int mn=2e9;
                for(int j=1;j<=n;j++)
                    if(plan[j])mn=min(mn,dist(i,j));
                mx=max(mx,mn);
            }
            ans=min(ans,mx);
        }
        return;
    }
    plan[x]=true;
    sel(x+1,cnt+1);
    plan[x]=false;
    sel(x+1,cnt);
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>k,cnt=0,ans=2e9;
        for(int i=1;i<=n;i++)head[i]=0;
        for(int i=1,u,v;i<n;i++)cin>>u>>v,add(u,v),add(v,u);
        dep[1]=1,dfs(1,0);
        sel(1,0);
        cout<<ans<<endl;
    }
    return 0;
}