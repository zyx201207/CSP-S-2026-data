#include<bits/stdc++.h>
using namespace std;
long long gunmu,n,m,d,q,k,la,ans[500005];
int li[500005];
long long w[500005],c[505][500005];
vector <int> e[500005];
void dfs(int u,int fa){
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v==fa) continue;
        if(li[v]!=li[u]){
            if(ans[v]!=0) ans[v]=min(ans[v],ans[u]+c[li[v]][v]+c[li[u]][v]);
            else ans[v]=ans[u]+c[li[v]][v]+c[li[u]][v];
        }
        else{
            if(ans[v]!=0) ans[v]=min(ans[v],ans[u]);
            else ans[v]=ans[u];
        }
        dfs(v,u);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>gunmu>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int v,w;
            //
            cin>>v>>w;
            li[v]=i;
            c[i][v]=w;
            if(j==1){
                la=v;
                continue;
            }
            e[la].push_back(v);
            e[v].push_back(la);
            la=v;
        }
    }
    int t=q;
    while(t--){
        int st,en;
        cin>>st>>en;
        ans[st]=w[st]+w[en]+c[li[st]][st]+c[li[en]][en];
        dfs(st,0);
        cout<<ans[en]+w[en]<<endl;
    }
    return 0;
}
