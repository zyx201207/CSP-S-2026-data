#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,INF=1e18;
int c,t;
int n,k;
vector<int> vec[N];
int dep[N],st[N][25];
bool vis[N];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    for(int i=0;i<vec[u].size();i++){
        if(vec[u][i]!=fa){
            dfs(vec[u][i],u);
        }
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    for(int i=25;i>=0;i--){
        if(dep[st[u][i]]>=dep[v]){
            u=st[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=25;i>=0;i--){
        if(st[u][i]!=st[v][i]){
            u=st[u][i];
            v=st[v][i];
        }
    }
    return st[u][0];
}
int cal(int x,int y){
    int lc=lca(x,y);
    return abs(dep[lc]-dep[x])+abs(dep[lc]-dep[y]);
}
void dfs2(int u,int mas){
    vis[u]=1;
    for(int i=0;i<vec[u].size();i++){
        if(vis[vec[u][i]]==0&&mas&(1<<(vec[u][i]-1))){
            dfs2(vec[u][i],mas);
        }
    }
}
bool check(int mas){
    memset(vis,0,sizeof vis);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&mas&(1<<(i-1))){
            dfs2(i,mas);
            cnt++;
        }
    }
    if(cnt>2){
        return false;
    }else{
        return true;
    }
}
void solve3(){
    int minx=INF;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        vec[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0);
    for(int j=1;j<=25;j++){
        for(int i=1;i<=n;i++){
            st[i][j]=st[st[i][j-1]][j-1];
        }
    }
    for(int i=0;i<(1<<n);i++){
        int cnt=0,sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cnt++;
            }
        }
        if(cnt!=k){
            continue;
        }
        if(!check(i)){
            continue;
        }
        for(int j=1;j<=n;j++){
            int minn=INF;
            for(int l=1;l<=n;l++){
                if(i&(1<<(l-1))){
                    minn=min(minn,cal(i,j));
                }
            }
            if(j==1){
                sum=minn;
                continue;
            }
            sum=max(sum,minn);
        }
        //cout<<i<<" "<<sum<<'\n';
        minx=min(minx,sum);
    }
    cout<<minx<<'\n';
}
void solve2(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        vec[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int m=(n-1)>>1;
    for(int i=1;i<=n;i++){
        if(n/i+1<=k){
            cout<<i<<'\n';
            return ;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        so
        if(c==13||c==14){
            solve2();
        }else{
            solve3();
        }
    }
    return 0;
}
