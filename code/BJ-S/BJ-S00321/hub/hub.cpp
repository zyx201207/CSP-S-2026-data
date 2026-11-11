#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,INF=0x3f3f3f3f3f3f3f3f;
vector<int> g[N];
int ans=INF,root=1;
int a[N];
int ld[N];
int f1=0;
int n,k;
void dfs(int x,int fa,int dep){
    if(a[x]==1) dep=0;
    ld[x]=dep;
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i];
        if(v==fa) continue;
        dfs(v,x,dep+1);
        ld[x]=min(ld[v]+1,ld[x]);
    }
    return ;
}
int fans=INF;
void dfs1(int x,int nk){
    if(nk>k||x>n+1) return ;
    if(x==n+1&&nk==k){
        dfs(f1,-1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,ld[i]);
        }
        if(ans<fans){
            fans=ans;
        }
        return ;
    }
    a[x]=0;
    dfs1(x+1,nk);
    a[x]=1;
    if(f1==0) f1=x;
    dfs1(x+1,nk+1);
    f1=0;
    return ;
}
void subtask1(){
    dfs1(1,0);
    cout<<fans<<endl;
}
int c,t;
signed main(){
    ios::sync_with_stdio(false);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(c<=5){
            subtask1();
        }
    }
    return 0;
}

