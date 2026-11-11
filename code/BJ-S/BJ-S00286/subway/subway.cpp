#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,c,d,q,x,k,y;
ll f[N][N],w[M],ans;
vector<pair<int,ll>>g[M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            g[x].push_back({i,y});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            for(int k=j+1;k<g[i].size();k++){
                f[g[i][k].first][g[i][j].first]=f[g[i][j].first][g[i][k].first]=min(f[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        ans=INF;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                ans=min(ans,w[x]+w[y]+g[x][i].second+g[y][j].second+f[g[x][i].first][g[y][j].first]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
