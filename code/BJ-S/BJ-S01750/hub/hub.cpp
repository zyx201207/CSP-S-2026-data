#include<bits/stdc++.h>
using namespace std;
vector<int>g[17];
int dist[17];
void dfs(int x,int f){
    for(auto it:g[x]){
        if(it==f)continue;
        dist[it]=min(dist[it],dist[x]+1);
        dfs(it,x);
    }
}
void solve(){
    memset(dist,0x3f,sizeof dist);
    for(int i=0;i<=10;i++)g[i].clear();
    int n,k,res=0x3f3f3f3f;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<(1<<n);i++){
        memset(dist,0x3f,sizeof dist);
        int xs[k+1];
        int dig=i,cnt=0,idx=0;
        while(dig){
            cnt++;
            if(dig%2==1){
                xs[++idx]=cnt;
            }dig/=2;
        }if(idx!=k)continue;
        for(int j=1;j<=k;j++)dist[xs[j]]=0;
        for(int j=1;j<=k;j++)dfs(xs[j],0);
        int ans=0;
        for(int j=1;j<=n;j++)ans=max(ans,dist[j]);
        res=min(res,ans);
    }cout<<res<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
}
