#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const ll maxn=510,maxm=5e5+10,inf=1e17;
int C,n,m,d,q,k[maxn];
ll W[maxm],f[maxn][maxn];
struct NODE{
    int x;
    ll v;
};
vector<NODE>a[maxn];
vector<NODE>g[maxm];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>W[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int s,t;
            cin>>s>>t;
            a[i].push_back({s,t});
            g[s].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)f[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            for(int k=0;k<g[i].size();k++){
                auto J=g[i][j];
                auto K=g[i][k];
                f[J.x][K.x]=min(f[J.x][K.x],J.v+K.v);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i==k)continue;
            for(int j=1;j<=n;j++){
                if(i==j||k==j)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                auto I=g[x][i];
                auto J=g[y][j];
                ans=min(ans,I.v+J.v+f[I.x][J.x]);
                // cout<<I.x<<" "<<J.x<<" "<<f[I.x][J.x]<<'\n';
            }
        }
        cout<<ans+W[x]+W[y]<<'\n';//《《《《《
    }
}