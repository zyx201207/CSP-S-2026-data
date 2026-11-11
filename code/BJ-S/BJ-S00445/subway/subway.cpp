#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=510;
const int maxm=5e5+10;
const int inf=1e18;
int w[maxn][maxn],n,m,c,d,q,l[maxm],k[maxn],f[maxn][maxn];
vector<int>sub[maxm];
vector<int>dis[maxm];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>l[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            sub[x].push_back(i);
            dis[x].push_back(y);
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)w[i][j]=w[j][i]=inf;
    for(int i=1;i<=n;i++)w[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<sub[i].size();j++){
            for(int k=j+1;k<sub[i].size();k++){
                w[sub[i][j]][sub[i][k]]=w[sub[i][k]][sub[i][j]]=min(w[sub[i][j]][sub[i][k]],dis[i][j]+dis[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)f[i][j]=w[i][j];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int ans=inf;
        int u,v;
        cin>>u>>v;
        for(int i=0;i<sub[u].size();i++){
            for(int j=0;j<sub[v].size();j++){
                ans=min(ans,l[u]+l[v]+dis[u][i]+dis[v][j]+f[sub[u][i]][sub[v][j]]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}