#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,d,q;
int w[N],len[510];
vector<array<int,2>> ln[510];
vector<array<int,2>> g[N];
int f[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    cin>>_>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>len[i];
        for(int j=1,x,y;j<=len[i];j++){
            cin>>x>>y;
            ln[i].push_back({x,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=n;i++){
        for(auto [x,y]:ln[i]){
            for(auto [ip,val]:g[x]){
                f[i][ip]=f[ip][i]=min(f[i][ip],val+y);
            }
            g[x].push_back({i,y});
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto [u1,v1]:g[x])
            for(auto [u2,v2]:g[y])
                ans=min(ans,f[u1][u2]+v1+v2);
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
