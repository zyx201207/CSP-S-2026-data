#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,s,q;
vector<ll> t[510],a[510];
int k[510];
ll f[510][510];
ll w[500010];
vector<pair<ll,ll> > b[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>s>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            b[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)b[i].size();j++){
            for(int k=0;k<(int)b[i].size();k++){
                f[b[i][j].first][b[i][k].first]=min(f[b[i][j].first][b[i][k].first],b[i][j].second+b[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(int j=0;j<(int)b[x].size();j++){
            for(int k=0;k<(int)b[y].size();k++){
                if(b[x][j].first==b[y][k].first)ans=min(ans,b[x][j].second+b[y][k].second);
                else ans=min(ans,f[b[x][j].first][b[y][k].first]+b[x][j].second+b[y][k].second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
