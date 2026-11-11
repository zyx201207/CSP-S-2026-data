#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int c,T,n,k;
vector<int> edge[1000010];
int fa[1000010];
bool vis[1000010];
int dis[1000010];
queue<int> q;
int ans=0x3f3f3f3f;
int dep[1000010];
int maxi=0;

void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

int find(int x){
    if(x==fa[x]){
        return x;
    }
    return fa[x]=find(fa[x]);
}

void link(int x,int y){
    fa[find(x)]=find(y);
}

bool check(){
    init();
    for(int i=1;i<=n;i++){
        if(vis[i]){
            for(int v:edge[i]){
                if(vis[v]){
                    link(i,v);
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i==fa[i] && vis[i]){
            cnt++;
        }
    }
    return cnt<=2;
}

void bfs(){
    for(int i=1;i<=n;i++){
        dis[i]=0x3f3f3f3f;
        if(vis[i]){
            dis[i]=0;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:edge[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

void dfs(int p,int sum){
    if(sum>k){
        return;
    }
    if(sum==k){
        if(!check()){
            return;
        }
        bfs();
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=max(sum,dis[i]);
        }
        ans=min(ans,sum);
        return;
    }
    if(p>n){
        return;
    }
    vis[p]=true;
    dfs(p+1,sum+1);
    vis[p]=false;
    dfs(p+1,sum);
}

void dfs1(int p,int fa){
    dep[p]=dep[fa]+1;
    if(dep[p]>dep[maxi]){
        maxi=p;
    }
    for(int v:edge[p]){
        if(v==fa || vis[v]){
            continue;
        }
        dfs1(v,p);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            edge[i].clear();
        }
        ans=0x3f3f3f3f;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        if(c==7){
            for(int i=1;i<=n;i++){
                vis[i]=true;
                int maxn=-1,max2=-1;
                for(int v:edge[i]){
                    maxi=0;
                    dfs1(v,0);
                    int tmp=maxi;
                    maxi=0;
                    dfs1(tmp,0);
                    if(dep[maxi]>=maxn){
                        max2=maxn;
                        maxn=dep[maxi];
                    }else if(dep[maxi]>=max2){
                        max2=dep[maxi];
                    }
                }
                ans=min(ans,max((maxn+1)/2,max2));
                vis[i]=false;
            }
        }else{
            dfs(1,0);
        }
        cout<<ans<<'\n';
    }
    return 0;
}