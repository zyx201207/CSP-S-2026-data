#include<bits/stdc++.h>
using namespace std;
int ccc,n,m,d,lll;
long long f[505][505];
int reach[505][500005];
long long val[500005];
vector<long long> to[500005];
vector<long long> nt[500005];
void floyd(){
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    for(int k=1+j;k<=n;k++)
    if(reach[j][i]!=-1&&reach[k][i]!=-1){
        if(f[j][k]==-1)
        f[j][k]=f[k][j]=1ll*(reach[j][i]+reach[k][i]);
        else
        f[j][k]=f[k][j]=min(f[j][k],1ll*(reach[j][i]+reach[k][i]));        
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1+j;k<=n;k++)
    if(f[j][i]!=-1&&f[k][i]!=-1&&i!=j&&i!=k){
        if(f[j][k]==-1)
        f[j][k]=f[k][j]=1ll*(f[j][i]+f[i][k]);
        else
        f[j][k]=f[k][j]=min(f[j][k],1ll*(f[j][i]+f[i][k]));        
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ccc>>n>>m>>d>>lll;
    for(int i=1;i<=m;i++)
    cin>>val[i];
    memset(reach,-1,sizeof(reach));
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++){
        int len;
        cin>>len;
        for(int j=1;j<=len;j++){
            int x,y;
            cin>>x>>y;
            reach[i][x]=y;
            to[x].push_back(i);
            nt[x].push_back(y);
        }
        f[i][i]=0;
    }
    floyd();
    while(lll--){
        int u,v;
        cin>>u>>v;
        long long ans=1e18;
        for(int i=0;i<to[u].size();i++)
        for(int j=0;j<to[v].size();j++)
        if(f[to[u][i]][to[v][j]]!=-1)
        ans=min(ans,1ll*(nt[u][i]+nt[v][j]+f[to[u][i]][to[v][j]]));
        ans+=val[u];
        ans+=val[v];
        cout<<ans<<"\n";
    }
    return 0;
}