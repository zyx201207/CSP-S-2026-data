#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],b[N],d[N][N],fa[N],dep[N],vis[N],s[N],n,m,m1,ans;
vector<int> k[N];
void dfs2(int x,int la){
    vis[x]=1;
    for(auto y:k[x]){
        if(y==la || !b[y])continue;
        dfs2(y,x);
    }return;
}
int check(){
    for(int i=1;i<=n;i++)vis[i]=0;
    int tot=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] && b[i]){
            tot++;dfs2(i,0);
        }
    }if(tot>2)return 1e9;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i])continue;
        int sum=1e9;
        for(int j=1;j<=m;j++){
            sum=min(sum,d[i][a[j]]);
        }cnt=max(cnt,sum);
    }return cnt;
}
void dfs1(int x,int la){
    if(x==m+1){
        ans=min(ans,check());return;
    }
    for(int i=la+1;i<=n;i++){
        if(s[i])continue;
        a[x]=i;b[i]=1;dfs1(x+1,i);b[i]=0;
    }return;
}
void dfs(int x,int la){
    bool op=1;
    for(auto y:k[x]){
        if(y==la)continue;
        op=0;dep[y]=dep[x]+1;fa[y]=x;dfs(y,x);
    }s[x]=op;m1-=op;
    return;
}
void solve(){
    cin>>n>>m;m1=n;
    for(int i=1;i<=n;i++)k[i].clear();
    for(int i=1;i<=n;i++)s[i]=0;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        k[u].push_back(v);
        k[v].push_back(u);
    }if(n==m){
        cout<<"0\n";return;
    }if(2*m>=n){
        cout<<"1\n";return;
    }dfs(1,0);
    m=min(m,m1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x=i,y=j,sum=0;
            while(x!=y){
                if(dep[x]>dep[y]){
                    x=fa[x];
                }else{
                    y=fa[y];
                }sum++;
            }d[i][j]=d[j][i]=sum;
        }
    }ans=1e9;dfs1(1,0);
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--)solve();
    return 0;
}
