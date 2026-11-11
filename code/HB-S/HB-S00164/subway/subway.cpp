#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],k,a,t,ans=1000000,s,e,vis[10005];
vector<vector<pair<int,int>>> v;
void dfs(int x,int sum){
    if(x==e){
        ans=min(ans,sum);
        return;
    }
    if(vis[x])return;
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
        dfs(v[x][i].first,sum+v[x][i].second);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            v[i+m].push_back({a,t});
            v[a].push_back({i+m,t});
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        cin>>s>>e;
        dfs(s,0);
        cout<<ans+w[s]+w[e]<<endl;
    }
    return 0;
}
