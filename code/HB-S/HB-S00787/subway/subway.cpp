//T2:100pts
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 500 + 10 , M = 5e5 + 10;
int c,n,m,d,q,w[M];
long long f[N][N],ans;
vector<pair<int,int> > sta[M];
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    long long y,z;
    for(int i=1,x;i<=n;++i){
        cin>>x;
        for(int j=1;j<=x;++j){
            cin>>y>>z;
            for(auto k:sta[y]) f[k.first][i]=f[i][k.first]=min(f[i][k.first],z+k.second);
            sta[y].push_back({i,z});
        }
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j){
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;++i) f[i][i]=0;
    for(int k=1;k<=n;++k){
        for(int j=1;j<=n;++j){
            for(int i=1;i<=n;++i){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        ans=LONG_LONG_MAX;
        cin>>y>>z;
        for(auto i:sta[y]) for(auto j:sta[z]) ans=min(ans,f[i.first][j.first]+i.second+j.second);
        cout<<ans+w[y]+w[z]<<'\n';
    }
    return 0;
}