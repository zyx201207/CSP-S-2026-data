#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010];
int n,k,ans;
vector<int> to[1010];
int dfs(int u,int fa,int val){
    int mi=INT_MAX;
    if(a[u])return val;
    for(int i=0;i<to[u].size();i++){
        int v=to[u][i];
        if(v==fa)continue;
        mi=min(dfs(v,u,val+1),mi);
    }
    return mi;
}
void ds(int u){
    if(!a[u])return;
    b[u]=1;
    for(int i=0;i<to[u].size();i++){
        int v=to[u][i];
        if(b[v])continue;
        ds(v);
    }
}
void find(int i,int k){
    if(i==n+1||k==0){
        int sum=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            b[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]&&!b[i]){
                cnt++;
                ds(i);
            }
        }
        if(cnt!=2)return;
        for(int i=1;i<=n;i++){
            sum=max(dfs(i,0,0),sum);
        }
        ans=min(ans,sum);
        return;
    }
    a[i]=1;
    find(i+1,k-1);
    a[i]=0;
    find(i+1,k);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>k;
        ans=INT_MAX;
        for(int i=1;i<=n;i++)to[i].clear();
        for(int i=2;i<=n;i++){
            int u,v;cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        find(1,k);
        cout<<ans<<'\n';
    }
    return 0;
}