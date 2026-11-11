#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500005],k[505],x,y,vis[500005],t1,ans;
vector<vector<pair<ll,ll>>>g;
vector<map<ll,ll>>change;
vector<vector<ll>>a,t;
void dfs(ll i,ll u,ll ti){
    if(u==y){
        ans=min(ans,ti+change[u][i]);
        return;
    }
    for(auto p:g[u]){
        ll v=p.first,h=p.second;
        if(vis[v]==t1) continue;
        vis[v]=t1;
        if(i==h) dfs(i,v,ti);
        else{
            if(i==0) dfs(h,v,ti+change[u][h]);
            else dfs(h,v,ti+change[u][h]+change[u][i]);
        }
        vis[v]=0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    g.resize(m+1);
    change.resize(m+1);
    a.resize(n+1);
    t.resize(n+1);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]+1);
        t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            change[a[i][j]][i]=t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<k[i];j++){
            g[a[i][j]].push_back({a[i][j+1],i});
            g[a[i][j+1]].push_back({a[i][j],i});
        }
    }
    while(q--){
        cin>>x>>y;
        t1++,ans=1e18;
        dfs(0,x,0);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
