#include<bits/stdc++.h>
using namespace std;
int w[500010],c,n,m,d,q,tsf[500010][501],ans=INT_MAX;
vector<int> node[500010];
bool bl[501];
vector<int> line[501];
void dfs(int cur,int t,int en){
    bl[cur]=1;
    if(t>=ans) return;
    for(auto i:line[cur]){
        if(i==en){
            ans=min(ans,t+w[i]+tsf[i][cur]);
            return;
        }
        for(auto j:node[i]){
            if(bl[j]) continue;
            dfs(j,t+tsf[i][j]+tsf[i][cur],en);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int u,v;cin>>u>>v;
            node[u].push_back(i);
            line[i].push_back(u);
            tsf[u][i]=v;
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        for(auto i:node[x]){
            dfs(i,w[x]+tsf[x][i],y);
            memset(bl,0,sizeof(bl));
        }
        cout<<ans<<'\n';
    }
    return 0;
}
