#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k,c,T,ans,a[N],dis[N];
bool vis[N];
vector<int>nxt[N];
void dfs(int u){
    for(int v:nxt[u]){
        if(a[v]&&!vis[v])vis[v]=1,dfs(v);
    }
}
inline int solve(){
    int res=0,num=0;
    queue<int>q;
    for(int i=1;i<=n;i++){
        dis[i]=N,vis[i]=0;
        if(a[i]==1)dis[i]=0,q.push(i);
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1&&!vis[i])vis[i]=1,dfs(i),num++;
    }
    if(num>2)return N;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:nxt[u]){
            if(dis[v]>dis[u]+1)dis[v]=dis[u]+1,q.push(v);
        }
    }
    for(int i=1;i<=n;i++)res=max(res,dis[i]);
    return res; 
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k,ans=n;
        for(int i=1;i<=n;i++)nxt[i].clear(),a[i]=0;
        for(int i=1,u,v;i<n;i++)cin>>u>>v,nxt[u].push_back(v),nxt[v].push_back(u);
        if(k==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    a[i]=a[j]=1,ans=min(ans,solve());
                    a[i]=a[j]=0;
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        for(int s=3;s<(1<<n);s++){
            int num=0;
            for(int i=0;i<n;i++){
                if(s&(1<<i))a[i+1]=1,num++;
            }
            if(num==k)ans=min(ans,solve());
            for(int i=0;i<n;i++){
                if(s&(1<<i))a[i+1]=0;
            }
        }
        cout<<ans<<'\n';
    }
}