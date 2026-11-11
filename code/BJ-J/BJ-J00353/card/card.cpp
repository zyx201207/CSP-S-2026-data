#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],last[N],fa[N],sz[N],ans[N];
vector<pair<int,int> > g[N];//dfn real
void dfs(int u,int f){
    fa[u]=f;
    sz[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first;
        //cout<<u<<v<<endl;
        if(v!=f){
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(last[a[i]] != i) g[last[a[i]]].push_back({i,a[i]});
        else if(i!=n) g[i+1].push_back({i,a[i]});
    }
    dfs(n,0);
    //for(int i=1;i<=n;i++) cout<<fa[i]<<endl;
    for(int i=1;i<=n;i++){
        ans[a[i]]=max(ans[a[i]],sz[i]);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    // \|/
    return 0;
}
