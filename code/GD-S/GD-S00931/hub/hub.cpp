#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+5;
int c,t,n,k,tot=0,last=1e18,dis[maxn][maxn];
bool flag[maxn];
vector<int>G[maxn];
void cal(int id,int fa,int y){
    dis[y][id]=dis[y][fa]+1;
    for(int v:G[id]){
        if(v!=fa)cal(v,id,y);
    }
}
void dfs(int id,int need){
    if(id==n+1){
        if(need!=0)return;
        int ans=0;
        for(int i=1;i<=n;i++){
            int res=1e18;
            if(!flag[i]){
                cal(i,0,i);
                for(int j=1;j<=n;j++)
                    if(flag[j])res=min(res,dis[i][j]-1);
            }
            if(res!=1e18)ans=max(ans,res);
        }
        last=min(last,ans);
        return;
    }
    if(need>0){
        flag[id]=1;
        dfs(id+1,need-1);
    }
    flag[id]=0;
    dfs(id+1,need);
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    last=1e18;
    dfs(1,k);
    cout<<last<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)solve();
    return 0;
}