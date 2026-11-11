#include<bits/stdc++.h>
using namespace std;
#define int long long
int dis[505][505],c,n,k,a,t,m,q,d,w[500005],u,v;
struct node{
    int id,val;
};
vector<node>s[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            s[a].push_back(node{i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<s[i].size();j++)
            for(int l=j+1;l<s[i].size();l++){
                dis[s[i][j].id][s[i][l].id]=min(dis[s[i][j].id][s[i][l].id],s[i][j].val+s[i][l].val);
                dis[s[i][l].id][s[i][j].id]=min(dis[s[i][l].id][s[i][j].id],s[i][j].val+s[i][l].val);
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        cin>>u>>v;
        int ans=2e18;
        for(auto d1:s[u])
            for(auto d2:s[v]) ans=min(ans,dis[d1.id][d2.id]+w[u]+w[v]+d1.val+d2.val);
        cout<<ans<<"\n";
    }
    return 0;
}