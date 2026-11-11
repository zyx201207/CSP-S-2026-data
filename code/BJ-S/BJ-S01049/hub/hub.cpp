#include<iostream>
#include<vector>
using namespace std;
const int maxn=101000;
int c,T,n,k,uuuu,vvvv;
vector<int>v[maxn];int dis[maxn],vis[maxn];
void dfs(int p,int f){
    if(dis[p]<100)return;
    for(auto u:v[p])if(u!=f)dfs(u,p),dis[p]=min(dis[p],dis[u]+1);
}
void dfs2(int i,int p){
    vis[p]=1;
    for(auto u:v[p])if((i&1<<u-1)&&!vis[u])dfs2(i,u);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++)cin>>uuuu>>vvvv,v[uuuu].push_back(vvvv),v[vvvv].push_back(uuuu);
        if(c==13||c==14){
            if(k==n)cout<<0<<"\n";
            else cout<<max(1,((n-1)/2-k+3)/4+1)<<"\n";
            continue;
        }
        if(c<=3){
            int ans=100;
            for(int i=1;i<(1<<n);i++){
                int D=0,tt=0;
                for(int j=1;j<=n;j++)if(i&1<<j-1)++tt;
                if(tt>k)continue;
                for(int j=1;j<=n;j++)dis[j]=100,vis[j]=0;
                for(int j=1;j<=n;j++)if(i&1<<j-1)dis[j]=0;
                for(int j=1;j<=n;j++)dfs(j,0),D=max(D,dis[j]);
                int tot=0;for(int j=1;j<=n;j++)if((i&1<<j-1)&&vis[j]==0)++tot,dfs2(i,j);
                if(tot<=2)ans=min(ans,D);
            }
            cout<<ans<<"\n";
            for(int i=1;i<=n;i++)v[i].clear(),v[i].shrink_to_fit();
        }
    }
    return 0;
}